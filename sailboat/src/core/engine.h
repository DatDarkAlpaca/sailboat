#pragma once
#include "context.h"
#include "common.h"
#include "core/view.h"

struct engine;
typedef void (*engine_callback)(struct engine* engine);
typedef void (*engine_update_callback)(struct engine* engine, f64 deltaTime);

typedef struct engine
{
    context context;

    engine_callback initializeCallback;
    engine_update_callback updateCallback;

    f64 minimumFrameTime;
} engine;

typedef struct engine_parameters
{
    u32 windowWidth;
    u32 windowHeight;
    const char* windowTitle;

    f64 minimumFrameTime;
} engine_parameters;

extern engine_parameters sail_DefaultParameters;

void engine_set_parameters(const engine_parameters* parameters);
void engine_initialize(engine* engine);

void engine_set_initialize_callback(engine* engine, engine_callback callback);
void engine_set_update_callback(engine* engine, engine_update_callback callback);

gl_handle engine_create_texture(context* context, const char* filepath, u64 channelAmount);

view *engine_add_view(engine *engine);

void engine_run(engine* engine);