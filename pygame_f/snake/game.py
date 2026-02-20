import pygame
from player import Player

# window size
window_size = width, height = 480, 480

pygame.init()
screen = pygame.display.set_mode(window_size)
clock = pygame.time.Clock()
running = True
# delta
dt = 0

snake_size = (40,40)
fps = 60
player_pos = pygame.Vector2(width/2, height/2)
pos = pygame.Rect(player_pos, (1, 1))

snake = Player(snake_size)
snake.grow(2)


# When using this class, everething getting faster
# body = Bodypart(snake_size, player_pos)

# import time

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill('blue')

    keys = pygame.key.get_pressed()

    snake.move(keys, screen, pos, dt)
    
    # body.move(keys, screen, pos, dt)

    dt = clock.tick(fps)
    pygame.display.flip()

pygame.quit()