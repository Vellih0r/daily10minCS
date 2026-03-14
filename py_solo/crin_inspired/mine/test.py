import pyautogui as pt
import keyboard as kb
from time import sleep
pt.FAILSAFE = True  

x = 1980
y = 1080

ninty_x = 600
ninty_y = 540
calibrate = 0.138
BLOCK_TIME = 0.6

def move_y(x_=0, y_=ninty_y):
    pt.moveRel(x_, y_)
    pt.moveRel(0, y_*calibrate)

# build box around character
def build_home(event):
    # move camera down
    # move_y(0, ninty_y//2)
    # build walls
    for i in range(4):
        sleep(0.1)
        pt.click(button='right')
        pt.moveRel(0, -ninty_y*0.25)
        pt.click(button='right')
        pt.moveRel(ninty_x, ninty_y*0.25)
        # sleep(0.1)
    # jump and place block on top
    pt.keyDown('space')
    sleep(0.2)
    pt.click(button='right')
    pt.keyUp('space')

    # move camera up and close the box
    move_y(0, -ninty_y*2)
    pt.click(button='right')

def tower(event):
    ''' build tower to the sky '''
    #move camera down
    move_y(0, ninty_y*2)
    # constantly jump
    pt.keyDown('space')
    # build 15 blocks
    for _ in range(15):
        sleep(0.1)
        for _ in range(3):
            pt.click(button='right')
            sleep(0.01)
    pt.keyUp('space')

def down(event):
    ''' dig 15 blocks under player '''
    #move camera down
    move_y(0, ninty_y*2)
    pt.mouseDown()
    for _ in range(15):
        sleep(BLOCK_TIME)
    pt.mouseUp()
    
def bridge(event):
    #move camera down
    move_y(0, ninty_y*2)
    move_y(0, -50)

    pt.keyDown('ctrl')
    pt.keyDown('s')

    for _ in range(15):
        sleep(1)
        pt.click(button='right')
    
    pt.keyUp('s')
    pt.press('w')
    pt.keyUp('ctrl')

def test(event):
    x, y = pt.position()
    print(x,y)
    print(pt.pixel(x,y))
    sleep(0.2)

def mine(event):
    pt.moveRel(0, ninty_y*0.5)
    pt.keyDown('w')
    pt.mouseDown()
    for _ in range(1,41):
        sleep(BLOCK_TIME)
        if _ % 6 == 0:
            pt.mouseUp()
            pt.keyUp('w')

            pt.press('9')
            pt.moveRel(x*0.3, -ninty_y*0.5)
            pt.click(button='right')
            pt.press('1')
            pt.moveRel(-x*0.3, ninty_y*0.5)
            pt.keyDown('w')
            pt.mouseDown()
    pt.mouseUp()
    pt.keyUp('w')



kb.on_press_key('t', test)
kb.on_press_key('b', build_home)
kb.on_press_key('h', tower)
kb.on_press_key('j', down)
kb.on_press_key('n', bridge)
kb.on_press_key('m', mine)
kb.wait(';')