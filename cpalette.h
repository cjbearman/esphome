const static uint32_t dpalette[][14] = {
    { // Palette index 0 - Yellow and Green
        0xD5C67A,    // Date
        0x06A77D,    // Clock
        0xFFFFFF,    // Msg
        0x888888,    // Temp labels
        0x000000,    // Background
        0x0000FF,    // Freezing
        0x8888FF,    // Cold
        0x00FF00,    // Pleasant
        0xFFFF00,    // Warm
        0xFF0000,    // Hot
        0xFFFFFF,    // Alert FG
        0xFF0000,    // Alert BG
        0x00FF00,    // Alarm Active
        0x666666     // Alarm Inactive
    },
    { // Palette index 1 - Pastel
        0xecd4ff,    // Date
        0x9381ff,    // Clock
        0xadf7b6,    // Msg
        0xffeedd,    // Temp labels
        0x000000,    // Background
        0x6eb5ff,    // Freezing
        0xace7ff,    // Cold
        0xaaff9f,    // Pleasant
        0xfff5ba,    // Warm
        0xffabab,    // Hot
        0xFFFFFF,    // Alert FG
        0xFF0000,    // Alert BG
        0xaaff9f,    // Alarm Active
        0xffadad     // Alarm Inactive
    },
    { // Palette index 2 - Blues
        0x023e8a,    // Date
        0x48cae4,    // Clock
        0x0096c7,    // Msg
        0x023e8a,    // Temp labels
        0x000000,    // Background
        0x0096c7,    // Freezing
        0x0096c7,    // Cold
        0x0096c7,    // Pleasant
        0x0096c7,    // Warm
        0x0096c7,    // Hot
        0xFFFFFF,    // Alert FG
        0xFF0000,    // Alert BG
        0x0096c7,    // Alarm Active
        0x003045e     // Alarm Inactive
    },
    { // Palette index 3 - Greens
        0x38b000,    // Date
        0x9ef01a,    // Clock
        0xccff33,    // Msg
        0x38b000,    // Temp labels
        0x000000,    // Background
        0x9ef01a,    // Freezing
        0x9ef01a,    // Cold
        0x9ef01a,    // Pleasant
        0x9ef01a,    // Warm
        0x9ef01a,    // Hot
        0xFFFFFF,    // Alert FG
        0xFF0000,    // Alert BG
        0x9ef01a,    // Alarm Active
        0x007200     // Alarm Inactive
    },
    { // Palette index 3 - Monochrome
        0x888888,    // Date
        0xffffff,    // Clock
        0xffffff,    // Msg
        0x888888,    // Temp labels
        0x000000,    // Background
        0xffffff,    // Freezing
        0xffffff,    // Cold
        0xffffff,    // Pleasant
        0xffffff,    // Warm
        0xffffff,    // Hot
        0xFFFFFF,    // Alert FG
        0xFF0000,    // Alert BG
        0x00FF00,    // Alarm Active
        0x666666     // Alarm Inactive

    }

};

const static uint32_t npalette[][2] = {
{
    0xFF0000,    // RED
    0x000000,
},
{
    0x00FF00,    // GRN
    0x000000,
},
{
    0xFFFF00,    // YLW
    0x000000,
},
{
    0x0000FF,    // BLUE
    0x000000,
},
{
    0xFFFFFF,    // WHT
    0x000000,
},
{ 
    0x000000,  // BLK on WHT
    0xFFFFFF
}
};

Color PAL_DATE, PAL_CLOCK, PAL_MSG, PAL_LABELS, PAL_BACKGROUND, PAL_FREEZING, 
    PAL_COLD, PAL_PLEASANT, PAL_WARM, PAL_HOT, PAL_NIGHT_FOREGROUND, 
    PAL_NIGHT_BACKGROUND, PAL_ALERT_FOREGROUND, PAL_ALERT_BACKGROUND,
    PAL_ALARM_ACTIVE, PAL_ALARM_INACTIVE;

bool update_palette(int day_index, int night_index) {
    bool changed = false;
    static int last_day_index = -1;
    static int last_night_index = -1;
    if (last_day_index != day_index || last_night_index != night_index) {
        changed = true;
        last_day_index = day_index;
        last_night_index = night_index;
    }

    PAL_DATE = Color(dpalette[day_index][0]);
    PAL_CLOCK = Color(dpalette[day_index][1]);
    PAL_MSG = Color(dpalette[day_index][2]);
    PAL_LABELS = Color(dpalette[day_index][3]);
    PAL_BACKGROUND = Color(dpalette[day_index][4]);
    PAL_FREEZING = Color(dpalette[day_index][5]);
    PAL_COLD = Color(dpalette[day_index][6]);
    PAL_PLEASANT = Color(dpalette[day_index][7]);
    PAL_WARM = Color(dpalette[day_index][8]);
    PAL_HOT = Color(dpalette[day_index][9]);
    PAL_ALERT_FOREGROUND = Color(dpalette[day_index][10]);
    PAL_ALERT_BACKGROUND = Color(dpalette[day_index][11]);    
    PAL_ALARM_ACTIVE = Color(dpalette[day_index][12]);    
    PAL_ALARM_INACTIVE = Color(dpalette[day_index][13]);    
    PAL_NIGHT_FOREGROUND = Color(npalette[night_index][0]);
    PAL_NIGHT_BACKGROUND= Color(npalette[night_index][1]);

    return changed;
}

Color indoor(float temp) {
        return temp <= 68 ? PAL_FREEZING :
                temp <= 70 ? PAL_COLD :
                temp <= 75 ? PAL_PLEASANT :
                temp <= 78 ? PAL_WARM :
                PAL_HOT;
}

Color outdoor(float temp) {
        return temp <= 32 ? PAL_FREEZING :
                temp <= 55 ? PAL_COLD :
                temp <= 82 ? PAL_PLEASANT :
                temp <= 90 ? PAL_WARM :
                PAL_HOT;
}

