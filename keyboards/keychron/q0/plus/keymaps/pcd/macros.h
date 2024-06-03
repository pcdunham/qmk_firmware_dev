
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    switch (keycode) {

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("p.c.dunham@gmail.com");
            }
            return false;
    }
    return true;
};
