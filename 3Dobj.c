#include <raylib.h>

int main() {
    InitWindow(12800, 720, "model loading");

    Model model = LoadModel("suzanne.obj");

    Camera cam = {0};
    cam.position = (Vector3){0.0f,0.0f,0.0f};
    cam.up = (Vector3){0.0f,1.0f,0.0f};
    cam.fovy = 90.f;
    cam.projection = CAMERA_PERSPECTIVE;

    Vector3 pos = {0.0f,0.0f,0.0f};
    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);
        DrawModel(model, pos, 1.0f, WHITE);
        EndMode3D();
        DrawText(".obj from C", 10, GetScreenHeight()-20, 25, DARKGRAY);
        DrawFPS(10,10);
        EndDrawing();
    }

    UnloadModel(model);
    CloseWindow();
    return 0;
 }
