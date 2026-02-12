import pygame

# setup

size = width, height = 320, 240
speed = 300
fps = 60

pygame.init()
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()
running = True
# delta
dt = 0

# player position is in a senter of a screen
player_pos = pygame.Vector2(width/2, height/2)

while running:
    # poll for events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill('blue')

    # RENDER GAME HERE
    pygame.draw.circle(screen, "yellow", player_pos, 10)

    keys = pygame.key.get_pressed()
    if keys[pygame.K_w] and keys[pygame.K_d]:
        player_pos.y -= speed/2 * dt
        player_pos.x += speed/2 * dt
    elif keys[pygame.K_w] and keys[pygame.K_a]:
        player_pos.y -= speed/2 * dt
        player_pos.x -= speed/2 * dt
    elif keys[pygame.K_s] and keys[pygame.K_a]:
        player_pos.y += speed/2 * dt
        player_pos.x -= speed/2 * dt
    elif keys[pygame.K_s] and keys[pygame.K_d]:
        player_pos.y += speed/2 * dt
        player_pos.x += speed/2 * dt
    elif keys[pygame.K_a]: player_pos.x -= speed * dt
    elif keys[pygame.K_s]: player_pos.y += speed * dt
    elif keys[pygame.K_d]: player_pos.x += speed * dt
    elif keys[pygame.K_w]  : player_pos.y -= speed * dt


    # flip() - updates screen
    pygame.display.flip()
    # limits FPS
    # dt is delta time between frames
    # framerate - independent phisics
    dt = clock.tick(fps) /   1000

pygame.quit()
