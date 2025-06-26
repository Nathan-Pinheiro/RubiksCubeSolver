import sys
import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
from enum import Enum

class Color(Enum):
    WHITE = (1, 1, 1)
    RED = (1, 0, 0)
    BLUE = (0, 0, 1)
    YELLOW = (1, 1, 0)
    GREEN = (0, 1, 0)
    ORANGE = (1, 0.65, 0)

class RubiksCubeEdge:
    
    def __init__(self, id, color1, color2):
        self.id = id
        self.color1 = color1
        self.color2 = color2

    def draw(self, position, rotation):
        
        glPushMatrix()
        glTranslatef(*position)
        glRotatef(rotation[0], 1, 0, 0)
        glRotatef(rotation[1], 0, 1, 0)
        glRotatef(rotation[2], 0, 0, 1)
        glBegin(GL_QUADS)
        
        # Draw the first face of the edge
        glColor3fv(self.color1.value)
        glVertex3f(-0.5, 0.5, 0.5)
        glVertex3f(0.5, 0.5, 0.5)
        glVertex3f(0.5, -0.5, 0.5)
        glVertex3f(-0.5, -0.5, 0.5)
        
        # Draw the second face of the edge
        glColor3fv(self.color2.value)
        glVertex3f(0.5, 0.5, -0.5)
        glVertex3f(0.5, 0.5, 0.5)
        glVertex3f(0.5, -0.5, 0.5)
        glVertex3f(0.5, -0.5, -0.5)
        
        glEnd()
        glPopMatrix()

class RubiksCubeCorner:
    
    def __init__(self, id, color1, color2, color3):
        self.id = id
        self.color1 = color1
        self.color2 = color2
        self.color3 = color3

    def draw(self, position, rotation, state):
        
        glPushMatrix()
        glTranslatef(*position)
        glRotatef(rotation[0], 1, 0, 0)
        glRotatef(rotation[1], 0, 1, 0)
        glRotatef(rotation[2], 0, 0, 1)
        glBegin(GL_QUADS)
        
        if state == 0 : colors = [self.color1, self.color2, self.color3]
        elif state == 1 : colors = [self.color3, self.color1, self.color2]
        else : colors = [self.color2, self.color3, self.color1]

        # Draw the first face of the edge
        glColor3fv(colors[0].value)
        glVertex3f(-0.5, 0.5, 0.5)
        glVertex3f(0.5, 0.5, 0.5)
        glVertex3f(0.5, -0.5, 0.5)
        glVertex3f(-0.5, -0.5, 0.5)
        
        # Draw the second face of the edge
        glColor3fv(colors[1].value)
        glVertex3f(0.5, 0.5, -0.5)
        glVertex3f(0.5, 0.5, 0.5)
        glVertex3f(0.5, -0.5, 0.5)
        glVertex3f(0.5, -0.5, -0.5)
        
        # Draw the second face of the edge
        glColor3fv(colors[2].value)
        glVertex3f(0.5, 0.5, 0.5)
        glVertex3f(0.5, 0.5, -0.5)
        glVertex3f(-0.5, 0.5, -0.5)
        glVertex3f(-0.5, 0.5, 0.5)
        glEnd()
        glPopMatrix()


class RubiksCubeMiddle:
    def __init__(self, id, color):
        self.id = id
        self.color = color

    def draw(self, position, rotation):
        glPushMatrix()
        glTranslatef(*position)
        glRotatef(rotation[0], 1, 0, 0)
        glRotatef(rotation[1], 0, 1, 0)
        glRotatef(rotation[2], 0, 0, 1)
        glBegin(GL_QUADS)
        glColor3fv(self.color.value)
        glVertex3f(-0.5, 0.5, 0)
        glVertex3f(0.5, 0.5, 0)
        glVertex3f(0.5, -0.5, 0)
        glVertex3f(-0.5, -0.5, 0)
        glEnd()
        glPopMatrix()

MIDDLES = [
    RubiksCubeMiddle(0, Color.WHITE),
    RubiksCubeMiddle(1, Color.YELLOW),
    RubiksCubeMiddle(2, Color.RED),
    RubiksCubeMiddle(3, Color.ORANGE),
    RubiksCubeMiddle(4, Color.GREEN),
    RubiksCubeMiddle(5, Color.BLUE),
]

MIDDLES_POSITIONS = [
    (0, 1.5, 0),    # Top face
    (0, -1.5, 0),   # Bottom face
    (0, 0, 1.5),    # Front face
    (0, 0, -1.5),   # Back face
    (-1.5, 0, 0),   # Left face
    (1.5, 0, 0),    # Right face
]

MIDDLES_ROTATION = [
    (90, 0, 0),     # Top face (white facing up)
    (-90, 0, 0),    # Bottom face (yellow facing down)
    (0, 0, 0),      # Front face (red facing forward)
    (0, 180, 0),    # Back face (orange facing backward)
    (0, -90, 0),    # Left face (green facing left)
    (0, 90, 0),     # Right face (blue facing right)
]

EDGES = [
    RubiksCubeEdge(0, Color.WHITE, Color.GREEN),
    RubiksCubeEdge(1, Color.WHITE, Color.BLUE),
    RubiksCubeEdge(2, Color.WHITE, Color.RED),
    RubiksCubeEdge(3, Color.WHITE, Color.ORANGE),
    RubiksCubeEdge(4, Color.YELLOW, Color.GREEN),
    RubiksCubeEdge(5, Color.YELLOW, Color.BLUE),
    RubiksCubeEdge(6, Color.YELLOW, Color.RED),
    RubiksCubeEdge(7, Color.YELLOW, Color.ORANGE),
    RubiksCubeEdge(8, Color.GREEN, Color.RED),
    RubiksCubeEdge(9, Color.BLUE, Color.RED),
    RubiksCubeEdge(10, Color.GREEN, Color.ORANGE),
    RubiksCubeEdge(11, Color.BLUE, Color.ORANGE),
]

EDGE_POSITIONS = [
    (-1, 1, 0),     # Top-left edge
    (1, 1, 0),      # Top-right edge
    (0, 1, 1),      # Top-front edge
    (0, 1, -1),     # Top-back edge
    (-1, -1, 0),    # Bottom-left edge
    (1, -1, 0),     # Bottom-right edge
    (0, -1, 1),     # Bottom-front edge
    (0, -1, -1),    # Bottom-back edge
    (-1, 0, 1),     # Left-front edge
    (1, 0, 1),      # Right-front edge
    (-1, 0, -1),    # Left-back edge
    (1, 0, -1),     # Right-back edge
]

EDGE_ROTATIONS = [
    (90, 180, 0),       # Top-left edge (white facing up, green facing left)
    (-90, 0, 0),        # Top-right edge (white facing up, blue facing right)
    (-90, 0, -90),      # Top-front edge (white facing up, red facing forward)
    (90, 180, -90),     # Top-back edge (white facing up, orange facing backward)
    (-90, 180, 0),      # Bottom-left edge (green facing left, yellow facing down)
    (90, 0, 0),         # Bottom-right edge (blue facing right, yellow facing down)
    (-90, 180, -90),    # Bottom-front edge (red facing forward, yellow facing down)
    (90, 0, -90),       # Bottom-back edge (orange facing backward, yellow facing down)
    (0, -90, 0),        # Left-front edge (green facing left, red facing forward)
    (180, 90, 0),       # Right-front edge (blue facing right, red facing forward)
    (180, -90, 0),      # Left-back edge (green facing left, orange facing backward)
    (0, 90, 0),         # Right-back edge (blue facing right, orange facing backward)
]

CORNERS = [
    RubiksCubeCorner(0, Color.WHITE, Color.GREEN, Color.RED),
    RubiksCubeCorner(1, Color.BLUE, Color.WHITE, Color.RED),
    RubiksCubeCorner(2, Color.WHITE, Color.ORANGE, Color.GREEN),
    RubiksCubeCorner(3, Color.WHITE, Color.BLUE, Color.ORANGE),
    RubiksCubeCorner(4, Color.GREEN, Color.YELLOW, Color.RED),
    RubiksCubeCorner(5, Color.YELLOW, Color.BLUE, Color.RED),
    RubiksCubeCorner(6, Color.YELLOW, Color.GREEN, Color.ORANGE),
    RubiksCubeCorner(7, Color.YELLOW, Color.ORANGE, Color.BLUE),
]

CORNER_POSITIONS = [
    (-1, 1, 1),
    (1, 1, 1),
    (-1, 1, -1),
    (1, 1, -1),
    (-1, -1, 1),
    (1, -1, 1),
    (-1, -1, -1),
    (1, -1, -1),
]

CORNER_ROTATIONS = [
    (90, 180, 0),       # Top-front-left corner (white facing up, green left, red front)
    (90, 90, 0),        # Top-front-right corner (white facing up, blue right, red front)
    (90, 180, -90),     # Top-back-left corner (white facing up, green left, orange back)
    (-90, 0, 0),        # Top-back-right corner (white facing up, blue right, orange back)
    (0, -90, -90),      # Bottom-front-left corner (yellow facing down, green left, red front)
    (90, 0, 0),         # Bottom-front-right corner (yellow facing down, blue right, red front)
    (-90, 180, 0),      # Bottom-back-left corner (yellow facing down, green left, orange back)
    (90, 0, -90),       # Bottom-back-right corner (yellow facing down, blue right, orange back)
]

class RubiksCube:
    
    def __init__(self, middles_idxs: list[int] = list(range(6)), edges_idxs: list[int] = list(range(12)), corners_idxs: list[int] = list(range(8)), corners_states: list[int] = list(0 for _ in range(8))):
        """Initialize the Rubik's Cube with default colors."""
        self.middles_idxs: list[int] = middles_idxs
        self.edges_idxs: list[int] = edges_idxs
        self.corners_idxs: list[int] = corners_idxs
        self.corners_states: list[int] = corners_states

    def draw(self):
        """Draw the Rubik's Cube."""
        for i, middles_idxs in enumerate(self.middles_idxs):
            MIDDLES[middles_idxs].draw(MIDDLES_POSITIONS[i], MIDDLES_ROTATION[i])
            
        for i, edges_idx in enumerate(self.edges_idxs):
            EDGES[edges_idx].draw(EDGE_POSITIONS[i], EDGE_ROTATIONS[i])
            
        for i, corners_idx in enumerate(self.corners_idxs):
            CORNERS[corners_idx].draw(CORNER_POSITIONS[i], CORNER_ROTATIONS[i], self.corners_states[i])

    def move_U(self):
        
        tmp_corner = self.corners_idxs[0]
        self.corners_idxs[0] = self.corners_idxs[2]
        self.corners_idxs[2] = self.corners_idxs[3]
        self.corners_idxs[3] = self.corners_idxs[1]
        self.corners_idxs[1] = tmp_corner
        
        self.corners_states[0] = (self.corners_states[0] - 1) % 3
        self.corners_states[1] = (self.corners_states[1] + 1) % 3
        self.corners_states[2] = (self.corners_states[2] + 1) % 3
        self.corners_states[3] = (self.corners_states[3] - 1) % 3
        
        tmp_edge = self.edges_idxs[0]
        self.edges_idxs[0] = self.edges_idxs[3]
        self.edges_idxs[3] = self.edges_idxs[1]
        self.edges_idxs[1] = self.edges_idxs[2]
        self.edges_idxs[2] = tmp_edge

    def move_D(self):
        tmp_corner = self.corners_idxs[4]
        self.corners_idxs[4] = self.corners_idxs[6]
        self.corners_idxs[6] = self.corners_idxs[7]
        self.corners_idxs[7] = self.corners_idxs[5]
        self.corners_idxs[5] = tmp_corner
        
        tmp_edge = self.edges_idxs[4]
        self.edges_idxs[4] = self.edges_idxs[7]
        self.edges_idxs[7] = self.edges_idxs[5]
        self.edges_idxs[5] = self.edges_idxs[6]
        self.edges_idxs[6] = tmp_edge

    def move_F(self):
        tmp_corner = self.corners_idxs[0]
        self.corners_idxs[0] = self.corners_idxs[4]
        self.corners_idxs[4] = self.corners_idxs[5]
        self.corners_idxs[5] = self.corners_idxs[1]
        self.corners_idxs[1] = tmp_corner
        
        tmp_edge = self.edges_idxs[2]
        self.edges_idxs[2] = self.edges_idxs[8]
        self.edges_idxs[8] = self.edges_idxs[6]
        self.edges_idxs[6] = self.edges_idxs[9]
        self.edges_idxs[9] = tmp_edge

    def move_B(self):
        tmp_corner = self.corners_idxs[2]
        self.corners_idxs[2] = self.corners_idxs[6]
        self.corners_idxs[6] = self.corners_idxs[7]
        self.corners_idxs[7] = self.corners_idxs[3]
        self.corners_idxs[3] = tmp_corner
        
        tmp_edge = self.edges_idxs[3]
        self.edges_idxs[3] = self.edges_idxs[10]
        self.edges_idxs[10] = self.edges_idxs[7]
        self.edges_idxs[7] = self.edges_idxs[11]
        self.edges_idxs[11] = tmp_edge

    def move_L(self):
        tmp_corner = self.corners_idxs[0]
        self.corners_idxs[0] = self.corners_idxs[2]
        self.corners_idxs[2] = self.corners_idxs[6]
        self.corners_idxs[6] = self.corners_idxs[4]
        self.corners_idxs[4] = tmp_corner
        
        tmp_edge = self.edges_idxs[0]
        self.edges_idxs[0] = self.edges_idxs[8]
        self.edges_idxs[8] = self.edges_idxs[4]
        self.edges_idxs[4] = self.edges_idxs[10]
        self.edges_idxs[10] = tmp_edge

    def move_R(self):
        tmp_corner = self.corners_idxs[1]
        self.corners_idxs[1] = self.corners_idxs[5]
        self.corners_idxs[5] = self.corners_idxs[7]
        self.corners_idxs[7] = self.corners_idxs[3]
        self.corners_idxs[3] = tmp_corner
        
        tmp_edge = self.edges_idxs[1]
        self.edges_idxs[1] = self.edges_idxs[11]
        self.edges_idxs[11] = self.edges_idxs[7]
        self.edges_idxs[7] = self.edges_idxs[9]
        self.edges_idxs[9] = tmp_edge
    
    def move_Uprime(self):
        pass

    def move_Dprime(self):
        pass

    def move_Fprime(self):
        pass

    def move_Bprime(self):
        pass

    def move_Lprime(self):
        pass

    def move_Rprime(self):
        pass

# Initialize pygame
pygame.init()

# Screen dimensions
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT), DOUBLEBUF | OPENGL)

# Enable depth testing
glEnable(GL_DEPTH_TEST)
pygame.display.set_caption("3D Rubik's Cube Simulation")

# Colors
WHITE = (1, 1, 1)
BLACK = (0, 0, 0)
RED = (1, 0, 0)
GREEN = (0, 1, 0)
BLUE = (0, 0, 1)
YELLOW = (1, 1, 0)
ORANGE = (1, 0.65, 0)

# Instantiate the Rubik's Cube
rubiks_cube = RubiksCube()

# Rotation angles
rotation_x = 0
rotation_y = 0

# Mouse tracking
mouse_down = False
last_mouse_pos = (0, 0)

# Main loop
running = True
while running:
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluPerspective(45, (WIDTH / HEIGHT), 0.1, 50.0)
    glTranslatef(0.0, 0.0, -15)

    # Apply rotations
    glRotatef(rotation_x, 1, 0, 0)
    glRotatef(rotation_y, 0, 1, 0)

    # Draw the Rubik's Cube
    rubiks_cube.draw()

    pygame.display.flip()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            # Rotate the cube
            if event.key == pygame.K_UP:
                rotation_x -= 5
            elif event.key == pygame.K_DOWN:
                rotation_x += 5
            elif event.key == pygame.K_LEFT:
                rotation_y -= 5
            elif event.key == pygame.K_RIGHT:
                rotation_y += 5

            # Perform Rubik's Cube moves
            elif event.key == pygame.K_u:
                rubiks_cube.move_U()
            elif event.key == pygame.K_d:
                rubiks_cube.move_D()
            elif event.key == pygame.K_f:
                rubiks_cube.move_F()
            elif event.key == pygame.K_b:
                rubiks_cube.move_B()
            elif event.key == pygame.K_l:
                rubiks_cube.move_L()
            elif event.key == pygame.K_r:
                rubiks_cube.move_R()
            elif event.key == pygame.K_q:  # Quit
                running = False

        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:  # Left mouse button
                mouse_down = True
                last_mouse_pos = event.pos
        elif event.type == pygame.MOUSEBUTTONUP:
            if event.button == 1:  # Left mouse button
                mouse_down = False
        elif event.type == pygame.MOUSEMOTION and mouse_down:
            dx, dy = event.pos[0] - last_mouse_pos[0], event.pos[1] - last_mouse_pos[1]
            rotation_x += dy * 0.2  # Adjust sensitivity if needed
            rotation_y += dx * 0.2  # Adjust sensitivity if needed
            last_mouse_pos = event.pos

pygame.quit()
sys.exit()
