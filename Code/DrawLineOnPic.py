# -*- coding: utf-8 -*-
"""
Created on Fri Feb 22 10:35:10 2019

@author: david
"""

import numpy as np
import cv2

img = cv2.imread('C:/Users/david/Desktop/OpenCV/Pics/watch.jpg', cv2.IMREAD_COLOR)
cv2.line(img,(0,0),(150,150),(255,255,255),15)
cv2.rectangle(img,(15,25), (200,150),(0,0,255),15)
cv2.circle(img,(100,63),55, (0,255,0), -1)
#text
font = cv2.FONT_HERSHEY_SIMPLEX

cv2.putText(img,'Text on screen!',(10,130),font, 1, (200,255,155),2, cv2.LINE_AA)
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()