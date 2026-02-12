from pygame import Rect, Vector2, draw, Color
import pygame

class Player:
    # TODO
    # review
    # head and body
    # direction for body
    # move each part
    # class for apple
    # better collors
    # score menu and restart
    def __init__(self, size: tuple, position: Vector2):
        self.OUTLINE_WIDTH = 3
        self.full_size = size
        self.inner_size = size[0]-self.OUTLINE_WIDTH*2, size[1]-self.OUTLINE_WIDTH*2
        self.color = Color("green")
        self.tail_length = 0
        self.direction = (0,1)

        # head and tail are separete prepared surfaces to display them
        self.head = pygame.Surface(size, pygame.SRCALPHA)
        self._create_head()
        self.tail = pygame.Surface(size, pygame.SRCALPHA)
        self._create_tail(self.tail)

    def move(self, keys, screen, position, delta):
        if keys[pygame.K_w]:
            self.direction = (0, 1)
        elif keys[pygame.K_a]:
            self.direction = (1, 0)
        elif keys[pygame.K_s]:
            self.direction = (0, -1)
        elif keys[pygame.K_d]:
            self.direction = (-1, 0)
        
        position.x -= (self.inner_size[0] * self.direction[0]) * delta/150
        position.y -= (self.inner_size[1] * self.direction[1]) * delta/150
        self.display(screen, position, self.direction)

    def grow(self, inc = 1):
        self.tail_length += inc

    def display(self, screen, position, direction):
        self._display_head(screen, position, direction)
        self._display_tail(screen, position, direction)

    # draw head of separate surface
    def _create_head(self):
        # base of head is just a tail bart
        self._create_tail(self.head)
        # add eyes
        eye_size = self.full_size[0]//6
        x = self.full_size[0]//5
        y = self.full_size[1]//3
        pygame.draw.rect(self.head, Color("black"), (x, y, eye_size, eye_size))
        pygame.draw.rect(self.head, Color("Black"), (x*3, y, eye_size, eye_size))

    def _create_tail(self, surface):
        surface.fill(Color("black"), (0,0, *self.full_size))
        pygame.draw.rect(surface, self.color, (self.OUTLINE_WIDTH, self.OUTLINE_WIDTH, *self.inner_size))

    # draw head surface with direction
    def _display_head(self, screen, position, direction):
        angle = {
            (0,1): 0,
            (-1,0): -90,
            (0,-1): 180,
            (1,0): 90
        }[direction]

        # create rotated surface and display it
        rotated = pygame.transform.rotate(self.head, angle)
        rect = rotated.get_rect(center=position.center)
        screen.blit(rotated, rect)

    def _display_tail(self, screen, position, direction):
        pos = position.copy()
        for _ in range(self.tail_length):
            part = self.tail
            
            # turn body in oposit direction
            part_direction = direction
            pos.x += self.inner_size[0] * part_direction[0]
            pos.y += self.inner_size[1] * part_direction[1]
            rect = part.get_rect(center=pos.center)
            screen.blit(part, rect)

    