# site to measure reastion time https://humanbenchmark.com/tests/reactiontime
# this code will emulate mouse to get time <20 ms

# init the library to read screen
import mss
import time
# init library to emulate mouse
import pyautogui
pyautogui.PAUSE = 0
pyautogui.FAILSAFE = False

pos = (400,400)
# blue color - site not started
blue = (34, 108, 167)
# green color - needs to be pressed
green = (30, 151, 80)
# set mouse position
pyautogui.moveTo(pos[0], pos[1])

with  mss.mss() as sct:
    # get small area of monitor
    monitor = {"left" : pos[0], "top": pos[1], "width" : 1, "height" : 1}

    while True:
        # get screenshot of monitor area
        img = sct.grab(monitor)

        color = img.pixel(0,0)

        if  color == green:
            pyautogui.click()
            break
        if color == blue:
            pyautogui.click()
            time.sleep(0.05)