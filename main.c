#include "raylib.h"

int main() {
  const int screen_width = 1280;
  const int screen_height = 720;
  InitWindow(screen_width, screen_height, "Game of Life");
  SetTargetFPS(10);

  const int grid_width  = screen_width  / 10;
  const int grid_height = screen_height / 10;

  bool grid[grid_width][grid_height] = {};

  for (int i = 0; i < grid_width; i++) {
    for (int j = 0; j < grid_height; j++) {
      grid[i][j] = GetRandomValue(0, 19) > 17;
    }
  }

  int cell_size = 10;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    for (int i = 0; i < grid_width; i++) {
      for (int j = 0; j < grid_height; j++) {
        bool is_cell_alive = grid[i][j];
        if (is_cell_alive)
          DrawRectangle(i * cell_size, j * cell_size, cell_size, cell_size, MAGENTA);

        int total_neighbors_alive = 0;
        if (grid[i - 1][j])
          total_neighbors_alive += 1;
        if (grid[i + 1][j])
          total_neighbors_alive += 1;
        if (grid[i][j + 1])
          total_neighbors_alive += 1;
        if (grid[i][j - 1])
          total_neighbors_alive += 1;
        if (grid[i - 1][j - 1])
          total_neighbors_alive += 1;
        if (grid[i - 1][j + 1])
          total_neighbors_alive += 1;
        if (grid[i + 1][j - 1])
          total_neighbors_alive += 1;
        if (grid[i + 1][j + 1])
          total_neighbors_alive += 1;

        if (is_cell_alive) {
          if(total_neighbors_alive < 2 || 3 < total_neighbors_alive)
            grid[i][j] = false;
        } else {
          if (total_neighbors_alive == 3)
            grid[i][j] = true;
        }
      }
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}