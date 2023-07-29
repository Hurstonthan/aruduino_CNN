import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject
cap = cv2.VideoCapture(0)
import numpy as np
import math
import time
import os
from CNN import CNN_model
detector = HandDetector(maxHands = 1)

filename = "C:/Users/Hurston/Arduino_Project/Data/"

offset = 10
imgSize = 300
counter = 0
#folder = "C:/Users/Hurston/Arduino_Project/Data/train/1"
#os.makedirs(folder)
arduino = SerialObject('COM6')

model_check = CNN_model(filename)


while True:
    success,img = cap.read()
    hands, img = detector.findHands(img)

    if hands:
        hand = hands[0]
        x,y,w,h = hand['bbox']
        imgCrop = img[y - offset :y+h+offset,x - offset :x+w+offset]
        try:
            imgCrop = cv2.cvtColor(imgCrop,cv2.COLOR_BGR2GRAY)
        except cv2.error:
            imgCrop = np.ones((imgSize,imgSize),np.uint8) * 255
        imgWhite = np.ones((imgSize,imgSize),np.uint8) * 255
        imgCropShape = imgCrop.shape
        abs_ratio = h / w
        imgSizeShape = 0
        if abs_ratio > 1:
            k = imgSize / h
            wCal = math.ceil(k*w)
            try:
                imgResize = cv2.resize(imgCrop,(abs(wCal),imgSize))
            except cv2.error:
                imgResize = cv2.resize(imgWhite,(abs(wCal),imgSize))
            imgSizeShape = imgResize.shape
            wGap = math.ceil(abs((imgSize - wCal)) / 2)
            imgWhite[:,wGap:wCal + wGap] = imgResize #Overlay the image
        else:
            k = imgSize / w
            hCal = math.ceil(k*h)
            hGap = math.ceil(abs((imgSize - hCal)) / 2)
            try:
                imgResize = cv2.resize(imgCrop,(imgSize,abs(hCal)))
            except cv2.error:
                imgResize = cv2.resize(imgWhite,(imgSize,abs(hCal)))
            #imgSizeShape = imgResize.shape
            imgWhite[hGap:hCal + hGap,:] = imgResize #Overlay the image
        try:
            imgCrop = cv2.cvtColor(imgCrop,cv2.COLOR_BGR2GRAY)
            #imgWhite = np.ones((imgSize,imgSize,3),np.uint8) * 255
            cv2.imshow("Image_crop",imgCrop)
        except cv2.error:
            cv2.imshow("Image_crop",imgWhite)
        
        #value = model_check.predict(imgWhite)
        #print("Here is the value -> %d",value)
        #arduino.sendData(value)

        cv2.imshow("Imagewhite",imgWhite)
    cv2.imshow("Image",img)
    key = cv2.waitKey(1)
    
        
    if key == ord("q"):
        cv2.destroyAllWindows()
        break
    