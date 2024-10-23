static uint32_t COL_DARK_BLUE = 0x0000FF;
static uint32_t COL_LIGHT_BLUE = 0x8888FF;
static uint32_t COL_GREEN = 0x00FF00;
static uint32_t COL_YELLOW = 0xFFFF00;
static uint32_t COL_ORANGE = 0xF5A530;
static uint32_t COL_RED = 0xFF0000;

uint32_t indoorColor(float temp) {
        return temp <= 68 ? COL_DARK_BLUE :
                temp <= 70 ? COL_LIGHT_BLUE :
                temp <= 74 ? COL_GREEN :
                temp <= 75 ? COL_YELLOW :
                temp <= 78 ? COL_ORANGE :
                COL_RED;
}

uint32_t outdoorColor(float temp) {
        return temp <= 32 ? COL_DARK_BLUE :
                temp <= 50 ? COL_LIGHT_BLUE :
                temp <= 75 ? COL_GREEN :
                temp <= 85 ? COL_YELLOW :
                temp <= 90 ? COL_ORANGE :
                COL_RED;
}

