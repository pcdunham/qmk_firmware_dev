
enum custom_keycodes {
    EMAIL = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("p.c.dunham@gmail.com");
            }
            return false;
    }
    return true;
};
