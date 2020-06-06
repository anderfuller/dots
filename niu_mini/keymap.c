#include QMK_KEYBOARD_H

#define BASE_LAYER 0
#define ACCENT_LAYER 1
#define GAMING_LAYER 2
#define NUMBER_LAYER 3
#define FUNCTION_LAYER 4
#define META_LAYER 5
#define KEYPAD_LAYER 6

#define KC_LARB LALT_T(KC_RBRC) //Left Alt Right Bracket
#define KC_LCLB KC_LCPO         //Left Control Left Bracket

#define KC_TOBL TO(BASE_LAYER)            //To Base Layer
#define KC_RGAL LT(ACCENT_LAYER, KC_RGUI) //Right Gui Accent Layer
#define KC_TOGL TO(GAMING_LAYER)          //To Gaming Layer
#define KC_MONL MO(NUMBER_LAYER)          //Momentary Number Layer
#define KC_MOFL MO(FUNCTION_LAYER)        //Momentary Function Layer
#define KC_MOML MO(META_LAYER)            //Momentary Meta Layer
#define KC_TOKL TO(KEYPAD_LAYER)          //To Keypad Layer

#define KC_SPAA XP(LOWERCASE_A, UPPERCASE_A)  //Spanish A
#define KC_SPAE XP(LOWERCASE_E, UPPERCASE_E)  //Spanish E
#define KC_SPAI XP(LOWERCASE_I, UPPERCASE_I)  //Spanish I
#define KC_SPAN XP(LOWERCASE_N, UPPERCASE_N)  //Spanish N
#define KC_SPAO XP(LOWERCASE_O, UPPERCASE_O)  //Spanish O
#define KC_SPAU XP(LOWERCASE_U, UPPERCASE_U)  //Spanish U
#define KC_SPAW XP(LOWERCASE_W, UPPERCASE_W)  //Spanish "W" (Ü)
#define KC_SPAQ XP(EXCLAMATION, QUESTION)     //Spanish Question/Exclamation mark

enum unicode_names //The Unicode map is used to have an easy Spanish layer
{
  LOWERCASE_A,
  LOWERCASE_E,
  LOWERCASE_I,
  LOWERCASE_N,
  LOWERCASE_O,
  LOWERCASE_U,
  LOWERCASE_W,
  UPPERCASE_A,
  UPPERCASE_E,
  UPPERCASE_I,
  UPPERCASE_N,
  UPPERCASE_O,
  UPPERCASE_U,
  UPPERCASE_W,
  EXCLAMATION,
  QUESTION
};

const uint32_t PROGMEM unicode_map[] =
{
  [LOWERCASE_A] = 0x00E1,
  [LOWERCASE_E] = 0x00E9,
  [LOWERCASE_I] = 0x00ED,
  [LOWERCASE_N] = 0x00F1,
  [LOWERCASE_O] = 0x00F3,
  [LOWERCASE_U] = 0x00FA,
  [LOWERCASE_W] = 0x00FC,
  [UPPERCASE_A] = 0x00C1,
  [UPPERCASE_E] = 0x00C9,
  [UPPERCASE_I] = 0x00CD,
  [UPPERCASE_N] = 0x00D1,
  [UPPERCASE_O] = 0x00D3,
  [UPPERCASE_U] = 0x00DA,
  [UPPERCASE_W] = 0x00DC,
  [EXCLAMATION] = 0x00A1,
  [QUESTION]    = 0x00BF
};

/* My particular PCB has a busted socket on the top right key, so I ran
 * some jumper cables from it to the 1u right spacebar. Hopefully this
 * diagram shows what I mean. THIS key is actually connected HERE.
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | THIS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | HERE |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * That's why the top right key never has anything and the key next to
 * the spacebar might not make sense.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

   /* Base Layer / Layer 0
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | LSPO |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /   | RSPC |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LCLB |   {  |   <  | LGUI | MONL |    Space    | MOFL | RGAL |   >  |  }   | LARB |
    * `-----------------------------------------------------------------------------------'
    * Note: Space-Cadet means on a keypress, the modifier is pressed immediately,
    * then the other key is sent if it is released soon enough.
    *
    * Fake Space-Cadet means on a keypress, nothing is sent immediately,
    * the modifer is sent after a moment if the key is still held, the other
    * key is sent if it is released soon enough. I use both because sending
    * an ALT code when you don't need it can mess up some programs.
    *
    *
    * Key to the keys:
    * LSPO = Left Shift Parentheses Open; Space-Cadet style shift and (
    * RSPC = Right Shift Parentheses Close; Space-Cadet style shift and )
    * LCLB = Left Control Left Bracket; Space-Cadet style control and [
    * MONL = Momentary Number Layer (Layer 3)
    * MOFL = Momentary Function Layer (Layer 4)
    * RGAL = Right Gui Accent Layer; Fake Space-Cadet style layer switch and GUI
    * LARB = Left Alt Right Bracket; Fake Space-Cadet style alt and ]
    */

    [BASE_LAYER] = LAYOUT_ortho_4x12
    (
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
      KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
      KC_LCLB, KC_LCBR, KC_LABK, KC_LGUI, KC_MONL, KC_SPC, KC_QUOT, KC_MOFL, KC_RGAL, KC_RABK, KC_RCBR, KC_LARB
    ),

    /* Accent Layer / Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |UC_MOD|   Q  |   Ü  |   É  |   R  |   T  |   Y  |   Ú  |   Í  |   Ó  |   P  |  '   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   Á  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | LSPO |   Z  |   X  |   C  |   V  |   B  |   Ñ  |   M  |   ,  |   .  | ¡  ¿ | RSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCLB |   {  |   <  | LGUI | MONL |    Space    | MOFL | RGAL |   >  |  }   | LARB |
     * `-----------------------------------------------------------------------------------'
     *
     * Note: All the Spanish characters have lowercase and uppercase
     * versions that can be used if shift is held.
     *
     * Key to the keys:
     * UC_MOD = Switch between the Unicode input methods defined in
     * config.h
     * ¡ ¿ = ¡ without shift, and ¿ with shift
     */

    [ACCENT_LAYER] = LAYOUT_ortho_4x12
    (
      UC_MOD,  KC_Q,    KC_SPAW, KC_SPAE, KC_R,    KC_T,    KC_Y,    KC_SPAU, KC_SPAI, KC_SPAO, KC_P,    KC_NO,
      KC_ESC,  KC_SPAA, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
      KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPAN, KC_M,    KC_COMM, KC_DOT,  KC_SPAQ, KC_RSPC,
      KC_LCLB, KC_LCBR, KC_LABK, KC_LGUI, KC_MONL, KC_SPC,  KC_QUOT, KC_MOFL, KC_TRNS, KC_RABK, KC_RCBR, KC_RARB
    ),

    /* Gaming Layer / Layer 2
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /   |RShift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LCtrl |      | LAlt | LGUI | MONL |    Space    | MOFL |  Up  | Left |Right | Down |
     * `-----------------------------------------------------------------------------------'
     * Note: This layer exists so when I press control it only presses
     * control.
     * The arrow keys are also added to the top layer. I realize that
     * it is not consistent with the default Planck layout but I've
     * never used that so ¯\_(ツ)_/¯
     */

    [GAMING_LAYER] = LAYOUT_ortho_4x12
    (
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL, KC_NO,   KC_LALT, KC_LGUI, KC_MONL, KC_SPC,  KC_QUOT, KC_MOFL, KC_UP,   KC_LEFT, KC_RGHT, KC_DOWN
    ),

    /* Number Layer / Layer 3
     * ,-----------------------------------------------------------------------------------.
     * |  !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |  +   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | LSPO |      |      |      |   `  |   ~  |   |  |   \  |      |      |      | RSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCLB |   {  |   <  | LGUI | TRNS |  Backspace  | MOML | RGAL |   >  |  }   | LARB |
     * `-----------------------------------------------------------------------------------'
     *
     * Key to the keys:
     * MOML = Momentary Meta layer
     * TRNS = Transparent, required by QMK when using MO(n)
     *
     * Note: Numbers, shifted numbers, backslash and tilde here.
     * Also backspace. This is done becuase if I hold the button to the
     * left of the spacebar and then press the spacebar, the cursor
     * moves towards the left. Delete is the opposite way.
     */

    [NUMBER_LAYER] = LAYOUT_ortho_4x12
    (
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_NO,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
      KC_LSPO, KC_NO,   KC_NO,   KC_NO,   KC_GRV,  KC_TILD, KC_PIPE, KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_RSPC,
      KC_LCLB, KC_LCBR, KC_LABK, KC_LGUI, KC_TRNS, KC_BSPC, KC_PLUS, KC_MOML, KC_RGAL, KC_RABK, KC_RCBR, KC_LARB
    ),

    /* Function Layer / Layer 4
     * ,-----------------------------------------------------------------------------------.
     * | Tab  | WH_U |  Up  | WH_D | Home |      |      |      |  F1  |  F2  |  F3  |  F4  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  | Left | Down |Right | End  |      |      |      |  F5  |  F6  |  F7  |  F8  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | LSPO |      |      |      |      |      |      |      |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCLB |   {  |   <  | LGUI | MOML |    Delete   | TRNS | RGAL |   >  |  }   | LARB |
     * `-----------------------------------------------------------------------------------'
     *
     * Key to the keys:
     * WH_U = Mouse wheel up
     * WH_D = Mouse wheel down
     *
     * Note: This one is pretty simple, WASD become arrow keys which
     * I really really like. F keys are also here in a grid.
     */

    [FUNCTION_LAYER] = LAYOUT_ortho_4x12
    (
      KC_TAB,  KC_WH_U, KC_UP,   KC_WH_D, KC_HOME, KC_NO,   KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_NO,
      KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
      KC_LSPO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      KC_LCLB, KC_LCBR, KC_LABK, KC_LGUI, KC_MOML, KC_DEL,  KC_F4,   KC_NO,   KC_RGAL, KC_RABK, KC_RCBR, KC_LARB
    ),

   /* Meta Layer / Layer 5
    * ,-----------------------------------------------------------------------------------.
    * | PgUp |LClick| MS_U |RClick| BRID |RGBUp |RGBDn | BRIU | ACL0 | ACL1 | ACL2 |RGBTOG|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | PgDn | MS_L | MS_D | MS_R | VOLD |Prev. | Next | VOLU |      |      |      | TOKL |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |Sat.Up|HueUp | VAI  | VAD  |HueDn |Sat.Dn|      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TOBL |      |      |      | TRNS |  Play/Pause | TRNS |      |      |      | TOGL |
    * `-----------------------------------------------------------------------------------'
    *
    * Key to the keys:
    * MS_U, MS_L, MS_D, MS_R = Mouse cursor up, left, down, right
    * BRIU, BRID = Laptop screen brightness up, down
    * RGBUp, RGBDn = Cycles through RGB modes up, down
    * ACL0, ACL1, ACL2 = Mouse accelaration levels
    * RGBTOG = Toggle RGB lights on and off
    * VOLU, VOLD = System volume up, down
    * TOKL = To Keypad Layer
    * Sat.Up, Sat.Dn = RGB saturation up, down
    * HueUP, HueDn = RGB hue up, down
    * VAI, VAD = RGB brightness up, down
    * TOBL = To Base Layer
    * TOGL = To Gaming Layer
    *
    * Note: This layer is used to access the other "base" layers being
    * the base layer, gaming layer, and keypad layer. Volume controls
    * are also right on the homing keys, making music playback really
    * nice. Play/Pause is right between both thumbs too.
    */

    [META_LAYER] = LAYOUT_ortho_4x12
    (
      KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BRID, RGB_MOD, RGB_RMOD,KC_BRIU, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
      KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, KC_MPRV, KC_MNXT, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_TOKL,
      KC_NO,   KC_NO,   KC_NO,   RGB_SAI, RGB_HUI, RGB_VAI, RGB_VAD, RGB_HUD, RGB_SAD, KC_NO,   KC_NO,   KC_NO,
      KC_TOBL, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_MPLY, RGB_TOG, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TOGL
    ),

    /* Keypad Layer / Layer 6
     * ,-----------------------------------------------------------------------------------.
     * | F13  | F14  | F15  | F16  |   /  |   7  |   8  |   9  |   +  | BTN3 | BTN4 | BTN5 |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | F17  | F18  | F19  | F20  |   *  |   4  |   5  |   6  |   +  | WH_L | WH_R | TOBL |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | F21  | F22  | F23  | F24  |   -  |   1  |   2  |   3  |Enter |CapsLk|ScrlLk|NumLk |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |RCtrl |RESET | RAlt | Menu |   =  |      0      |   .  |Enter |PrtScr|Insert|Pause |
     * `-----------------------------------------------------------------------------------'
     *
     * Key to the keys:
     * BTN3, BTN4, BTN5 = Middle, back, and forward mouse buttons
     * WH_L, WH_R = Mouse wheel left, right
     * RESET = Put the keyboard in reset mode to flash firmware
     *
     * Note: This layer is by far the most ridiculous one. The only
     * useable thing is just the keypad. I just decided to fill all the
     * keys up with every single key on a full-sized keyboard, and then
     * some.
     */

    [KEYPAD_LAYER] = LAYOUT_ortho_4x12
    (
      KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_BTN3, KC_BTN4, KC_NO,
      KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_WH_L, KC_WH_R, KC_TOBL,
      KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_CAPS, KC_SLCK, KC_NLCK,
      KC_RCTL, RESET,   KC_RALT, KC_APP,  KC_PEQL, KC_P0,   KC_BTN5, KC_PDOT, KC_PENT, KC_PSCR, KC_INS,  KC_PAUS
   )
};

void eeconfig_init_user(void)
{
  set_unicode_input_mode(UC_WIN); //I thought that WinCompose was a little overkill for what I needed
}
