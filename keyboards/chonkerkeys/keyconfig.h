#pragma once

#include "quantum.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    CH_CUSTOM = SAFE_RANGE,
    // zoom
    CH_ZOOM_MUTE_TOGGLE,
    CH_ZOOM_VIDEO_TOGGLE,
    CH_ZOOM_SHARE_SCREEN_START_STOP_TOGGLE,
    CH_ZOOM_RAISE_HAND_TOGGLE,
    CH_ZOOM_LEAVE_MEETING,
    // teams
    CH_TEAMS_MUTE_TOGGLE,
    CH_TEAMS_VIDEO_TOGGLE,
    CH_TEAMS_SHARE_SCREEN_START_STOP_TOGGLE,
    CH_TEAMS_RAISE_HAND_TOGGLE,
    CH_TEAMS_LEAVE_MEETING,
    // skype
    CH_SKYPE_MUTE_TOGGLE,
    CH_SKYPE_VIDEO_TOGGLE,
    CH_SKYPE_SHARE_SCREEN_START_STOP_TOGGLE,
    CH_SKYPE_RAISE_HAND_TOGGLE,
    CH_SKYPE_LEAVE_MEETING,
    // google meet
    CH_GOOGLE_MEET_MUTE_TOGGLE,
    CH_GOOGLE_MEET_VIDEO_TOGGLE,
    CH_GOOGLE_MEET_SHARE_SCREEN_START_STOP_TOGGLE,
    CH_GOOGLE_MEET_RAISE_HAND_TOGGLE,
    CH_GOOGLE_MEET_LEAVE_MEETING,
    // rest
    CH_VOLUME_UP,
    CH_VOLUME_DOWN,
    CH_MEDIA_NEXT,
    CH_MEDIA_PLAY_PAUSE,
    CH_SWITCH_WINDOW,
    CH_LAST_KEYCODE
};
