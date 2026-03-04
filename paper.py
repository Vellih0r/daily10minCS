from PIL import ImageGrab
import time
image = ImageGrab.grab()
color = image.getpixel((200,200))
print(color)



# Source - https://stackoverflow.com/a/15994043
# Posted by Ed Shway, modified by community. See post 'Timeline' for change history
# Retrieved 2026-03-04, License - CC BY-SA 3.0

# from pymouse import PyMouse

# m = PyMouse()
# m.position() #gets mouse current position coordinates
# m.move(x,y)
# m.click(x,y) #the third argument "1" represents the mouse button
# m.press(x,y) #mouse button press
# m.release(x,y) #mouse button release
