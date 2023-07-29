import numpy as np
import pandas as pd
import tensorflow as tf
import os
import random

from keras.utils.np_utils import to_categorical
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPool2D, BatchNormalization
from keras.optimizers import RMSprop, Adam
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ReduceLROnPlateau
from keras.models import load_model
import cv2

filename = "C:/Users/Hurston/Arduino_Project/Data/"

class CNN_model ():
    def __init__(self,link_connect):
        self.link = link_connect

        self.model = self.build_model()
        self.datagen = ImageDataGenerator(
            rotation_range=15,
            rescale=1./255,
            shear_range=0.1,
            zoom_range=0.2,
            horizontal_flip=True,
            width_shift_range=0.1,
            height_shift_range=0.1
        )
        
        self.learning_rate_reduction = ReduceLROnPlateau(monitor = 'val_accuracy',patience = 2,verbose = 1,factor = 0.5, min_lr = 0.00001)

        self.model_complete = self.load_model()

        self.test_ds = tf.keras.utils.image_dataset_from_directory(self.link + "test")
        self.labels = self.test_ds.class_names

    def build_model(self):
        model = Sequential()
        model.add(Conv2D(35,
                 kernel_size=(3,3),   ## kernel size nedir
                 activation='relu',
                 input_shape=(300,300,3),
                 padding = 'same'))

        model.add(BatchNormalization())
        model.add(MaxPool2D(pool_size=(2,2)))

        model.add(Conv2D(50,
                        kernel_size=(3,3),
                        padding='same',
                        activation='relu'))

        model.add(Dropout(0.2))
        model.add(BatchNormalization())

        model.add(MaxPool2D(pool_size=(2,2),
                            padding='same'))
        model.add(Flatten())
        model.add(Dense(units=9,activation='softmax'))
        model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
        #model.summary()
        return model
    
    def train(self):
        batch_size = 15
        train_ds = self.datagen.flow_from_directory(self.link + "train", target_size=(300,300), batch_size=batch_size,
                                      class_mode='sparse', subset='training')
        history = self.model.fit(
            train_ds,
            epochs = 1,
            callbacks = [self.learning_rate_reduction]
        )

    def predict (self,img):
        img_tf = tf.convert_to_tensor(img)
        img_resize = tf.image.resize(img_tf,(300,300))
        yhat = self.model_complete.predict(np.expand_dims(img_resize / 255,0))
        return self.labels[yhat.argmax()]

    def save_model (self):
        self.model.save('complete_saved_model/')

    def load_model (self):
        return load_model('C:/Users/Hurston/Arduino_Project/complete_saved_model')

    

#train_ds = CNN_model(filename)
# test_ds = CNN_model(filename)
        


# train_ds.train()
# train_ds.save_model()

#model_done = train_ds.load_model ()

# img = cv2.imread("C:/Users/Hurston/Arduino_Project/Data/test/2/test_1.jpg")
# print(train_ds.predict(img))