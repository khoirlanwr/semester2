import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    _, frame = cap.read()

    #converting frame into HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    #defining range of red color
    red_lower = np.array([136, 87, 111], np.uint8)
    red_upper = np.array([180, 255, 255], np.uint8)

    #defining range of blue color
    blue_lower = np.array([99, 115, 150], np.uint8)
    blue_upper = np.array([110, 255, 255], np.uint8)

    #defining range of yellow color
    yellow_lower = np.array([22, 60, 200], np.uint8)
    yellow_upper = np.array([60, 255, 255], np.uint8)

    #finding the range of red, yellow, blue 
    red = cv2.inRange(hsv, red_lower, red_upper)
    blue = cv2.inRange(hsv, blue_lower, blue_upper)
    yellow = cv2.inRange(hsv, yellow_lower, yellow_upper)

    #morpological transformation, dilation
    kernel = np.ones((5,5), "uint8")
    
    red = cv2.dilate(red, kernel)
    res = cv2.bitwise_and(frame, frame, mask = red)

    blue = cv2.dilate(blue, kernel)
    res1 = cv2.bitwise_and(frame, frame, mask = blue)

    yellow = cv2.dilate(yellow, kernel)
    res2 = cv2.bitwise_and(frame, frame, mask = yellow)

    #tracking red color
    (_, contours, hierarchy) = cv2.findContours(red, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        if(area > 300):
            x,y,w,h = cv2.boundingRect(contour)
            img = cv2.rectangle(frame, (x,y), (x+y, w+h), (0, 0, 255), 2)
            cv2.putText(img, "Red color", (x,y), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255))


    #tracking blue color
    (_, contours, hierarchy) = cv2.findContours(blue, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        if(area > 300):
            x,y,w,h = cv2.boundingRect(contour)
            img = cv2.rectangle(frame, (x,y), (x+y, w+h), (255, 0, 0), 2)
            cv2.putText(img, "Blue color", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0))
    
    #tracking yellow color
    (_, contours, hierarchy) = cv2.findContours(yellow, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        if(area > 300):
            x,y,w,h = cv2.boundingRect(contour)
            img = cv2.rectangle(frame, (x, y), (x+y, w+h), (0, 255, 0), 2)
            cv2.putText(img, "Yellow color", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 255, 0))


    cv2.imshow("Color tracking", frame)
    if cv2.waitKey(10) & 0xff == ord('q'):
        cap.release()
        cv2.destroyAllWindows()
        break

