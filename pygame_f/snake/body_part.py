from pygame import Color
import pygame

COLOR = Color("green")
speed_decrement = 200

class Bodypart:
    def __init__(self, full_size, inner_size):
        self.OUTLINE_WIDTH = 3
        self.full_size = full_size
        self.inner_size = inner_size
        self.direction = (0, 1)

        self.tail = pygame.Surface(full_size, pygame.SRCALPHA)
        self._create_tail(self.tail)

    def _create_tail(self, surface):
        surface.fill(Color("black"), (0,0, *self.full_size))
        pygame.draw.rect(surface, COLOR, (self.OUTLINE_WIDTH, self.OUTLINE_WIDTH, *self.inner_size))

    def _display_tail(self, screen, position, direction):
        pos = position.copy()

        part = self.tail
        pos.x += self.inner_size[0] * direction[0]
        pos.y += self.inner_size[1] * direction[1]
        rect = part.get_rect(center=pos.center)
        screen.blit(part, rect)

    def move(self, keys, screen, position, delta):
        if keys[pygame.K_w]:
            self.direction = (0, 1)
        elif keys[pygame.K_a]:
            self.direction = (1, 0)
        elif keys[pygame.K_s]:
            self.direction = (0, -1)
        elif keys[pygame.K_d]:
            self.direction = (-1, 0)
        
        position.x -= ((self.inner_size[0] * self.direction[0]) / speed_decrement) * delta 
        position.y -= ((self.inner_size[1] * self.direction[1]) / speed_decrement) * delta 
        self._display_tail(screen, position, self.direction)