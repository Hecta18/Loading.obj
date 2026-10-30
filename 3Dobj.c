#include <raylib.h>

int main() {
    InitWindow(12800, 720, "model loading");

    Model model = LoadModel("suzanne.obj");

    Camera cam = {0};
    cam.position = (Vector3){0.0f,5.0f,10.0f};
    cam.up = (Vector3){0.0f,2.0f,0.0f};
    cam.fovy = 45.f;
    cam.projection = CAMERA_PERSPECTIVE;

    Vector3 pos = {0.0f,0.0f,0.0f};

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);
          DrawModel(model, pos, 1.0f, DARKGRAY);
          DrawGrid(20, 10.0f);
        EndMode3D();
        DrawText(".obj from C", 10, GetScreenHeight()-20, 25, DARKGRAY);
        DrawFPS(10,10);
        EndDrawing();
    }

    UnloadModel(model);
    CloseWindow();
    return 0;
 }
