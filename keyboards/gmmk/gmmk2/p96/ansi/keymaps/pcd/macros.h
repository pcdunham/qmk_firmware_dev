
enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    WINTERM
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WINTERM:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_R));
                wait_ms(100);
                SEND_STRING("wt");
                wait_ms(50);
                tap_code16(KC_ENT);
            }
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("p.c.dunham@gmail.com");
            }
            return false;
    }
    return true;
};
