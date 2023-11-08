#include "raylib.h"

int main() {
  const int screen_width = 1280;
  const int screen_height = 720;
  InitWindow(screen_width, screen_height, "Game of Life");
  SetTargetFPS(10);

  const int grid_width = (screen_width / 10);
  const int grid_height = (screen_height / 10);
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
        if (grid[i][j])
          DrawRectangle(i * cell_size, j * cell_size, cell_size, cell_size,
                        GREEN);

        int sum = 0;
        if (grid[i - 1][j])
          sum += 1;
        if (grid[i + 1][j])
          sum += 1;
        if (grid[i][j + 1])
          sum += 1;
        if (grid[i][j - 1])
          sum += 1;
        if (grid[i - 1][j - 1])
          sum += 1;
        if (grid[i - 1][j + 1])
          sum += 1;
        if (grid[i + 1][j - 1])
          sum += 1;
        if (grid[i + 1][j + 1])
          sum += 1;

        if (grid[i][j]) {
          // cell is alive
          if (sum < 2)
            grid[i][j] = false;
          else if (sum < 4)
            grid[i][j] = true;
          else if (sum < 9)
            grid[i][j] = false;
        } else {
          // cell is dead
          if (sum == 3)
            grid[i][j] = true;
          else
            grid[i][j] = false;
        }
      }
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}