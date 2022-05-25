/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2021 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file SDL_hints.h
 *
 *  Official documentation for SDL configuration variables
 *
 *  This file contains functions to set and get configuration hints,
 *  as well as listing each of them alphabetically.
 *
 *  The convention for naming hints is SDL_HINT_X, where "SDL_X" is
 *  the environment variable that can be used to override the default.
 *
 *  In general these hints are just that - they may or may not be
 *  supported or applicable on any given platform, but they provide
 *  a way for an application or user to give the library a hint as
 *  to how they would like the library to work.
 */

#ifndef SDL_hints_h_
#define SDL_hints_h_

#include "SDL_stdinc.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \brief  A variable controlling whether the Android / iOS built-in
 *  accelerometer should be listed as a joystick device.
 *
 *  This variable can be set to the following values:
 *    "0"       - The accelerometer is not listed as a joystick
 *    "1"       - The accelerometer is available as a 3 axis joystick (the default).
 */
#define SDL_HINT_ACCELEROMETER_AS_JOYSTICK "SDL_ACCELEROMETER_AS_JOYSTICK"

/**
 *  \brief Specify the behavior of Alt+Tab while the keyboard is grabbed.
 *
 * By default, SDL emulates Alt+Tab functionality while the keyboard is grabbed
 * and your window is full-screen. This prevents the user from getting stuck in
 * your application if you've enabled keyboard grab.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL will not handle Alt+Tab. Your application is responsible
                 for handling Alt+Tab while the keyboard is grabbed.
 *   "1"       - SDL will minimize your window when Alt+Tab is pressed (default)
*/
#define SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED "SDL_ALLOW_ALT_TAB_WHILE_GRABBED"

/**
 *  \brief If set to "0" then never set the top most bit on a SDL Window, even if the video mode expects it.
 *      This is a debugging aid for developers and not expected to be used by end users. The default is "1"
 *
 *  This variable can be set to the following values:
 *    "0"       - don't allow topmost
 *    "1"       - allow topmost
 */
#define SDL_HINT_ALLOW_TOPMOST "SDL_ALLOW_TOPMOST"

/**
 * \brief Android APK expansion main file version. Should be a string number like "1", "2" etc.
 *
 * Must be set together with SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION.
 *
 * If both hints were set then SDL_RWFromFile() will look into expansion files
 * after a given relative path was not found in the internal storage and assets.
 *
 * By default this hint is not set and the APK expansion files are not searched.
 */
#define SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION "SDL_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION"
 
/**
 * \brief Android APK expansion patch file version. Should be a string number like "1", "2" etc.
 *
 * Must be set together with SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION.
 *
 * If both hints were set then SDL_RWFromFile() will look into expansion files
 * after a given relative path was not found in the internal storage and assets.
 *
 * By default this hint is not set and the APK expansion files are not searched.
 */
#define SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION "SDL_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION"

/**
 * \brief A variable to control whether the event loop will block itself when the app is paused.
 *
 * The variable can be set to the following values:
 *   "0"       - Non blocking.
 *   "1"       - Blocking. (default)
 *
 * The value should be set before SDL is initialized.
 */
#define SDL_HINT_ANDROID_BLOCK_ON_PAUSE "SDL_ANDROID_BLOCK_ON_PAUSE"

/**
 * \brief A variable to control whether SDL will pause audio in background
 *        (Requires SDL_ANDROID_BLOCK_ON_PAUSE as "Non blocking")
 *
 * The variable can be set to the following values:
 *   "0"       - Non paused.
 *   "1"       - Paused. (default)
 *
 * The value should be set before SDL is initialized.
 */
#define SDL_HINT_ANDROID_BLOCK_ON_PAUSE_PAUSEAUDIO "SDL_ANDROID_BLOCK_ON_PAUSE_PAUSEAUDIO"

/**
 * \brief A variable to control whether we trap the Android back button to handle it manually.
 *        This is necessary for the right mouse button to work on some Android devices, or
 *        to be able to trap the back button for use in your code reliably.  If set to true,
 *        the back button will show up as an SDL_KEYDOWN / SDL_KEYUP pair with a keycode of 
 *        SDL_SCANCODE_AC_BACK.
 *
 * The variable can be set to the following values:
 *   "0"       - Back button will be handled as usual for system. (default)
 *   "1"       - Back button will be trapped, allowing you to handle the key press
 *               manually.  (This will also let right mouse click work on systems 
 *               where the right mouse button functions as back.)
 *
 * The value of this hint is used at runtime, so it can be changed at any time.
 */
#define SDL_HINT_ANDROID_TRAP_BACK_BUTTON "SDL_ANDROID_TRAP_BACK_BUTTON"

/**
 *  \brief  A variable controlling whether controllers used with the Apple TV
 *  generate UI events.
 *
 * When UI events are generated by controller input, the app will be
 * backgrounded when the Apple TV remote's menu button is pressed, and when the
 * pause or B buttons on gamepads are pressed.
 *
 * More information about properly making use of controllers for the Apple TV
 * can be found here:
 * https://developer.apple.com/tvos/human-interface-guidelines/remote-and-controllers/
 *
 *  This variable can be set to the following values:
 *    "0"       - Controller input does not generate UI events (the default).
 *    "1"       - Controller input generates UI events.
 */
#define SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS "SDL_APPLE_TV_CONTROLLER_UI_EVENTS"

/**
 * \brief  A variable controlling whether the Apple TV remote's joystick axes
 *         will automatically match the rotation of the remote.
 *
 *  This variable can be set to the following values:
 *    "0"       - Remote orientation does not affect joystick axes (the default).
 *    "1"       - Joystick axes are based on the orientation of the remote.
 */
#define SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION "SDL_APPLE_TV_REMOTE_ALLOW_ROTATION"

/**
 *  \brief  A variable controlling the audio category on iOS and Mac OS X
 *
 *  This variable can be set to the following values:
 *
 *    "ambient"     - Use the AVAudioSessionCategoryAmbient audio category, will be muted by the phone mute switch (default)
 *    "playback"    - Use the AVAudioSessionCategoryPlayback category
 *
 *  For more information, see Apple's documentation:
 *  https://developer.apple.com/library/content/documentation/Audio/Conceptual/AudioSessionProgrammingGuide/AudioSessionCategoriesandModes/AudioSessionCategoriesandModes.html
 */
#define SDL_HINT_AUDIO_CATEGORY   "SDL_AUDIO_CATEGORY"

/**
 *  \brief Specify an application name for an audio device.
 *
 * Some audio backends (such as PulseAudio) allow you to describe your audio
 * stream. Among other things, this description might show up in a system
 * control panel that lets the user adjust the volume on specific audio
 * streams instead of using one giant master volume slider.
 *
 * This hints lets you transmit that information to the OS. The contents of
 * this hint are used while opening an audio device. You should use a string
 * that describes your program ("My Game 2: The Revenge")
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: probably the application's name or "SDL Application" if SDL
 * doesn't have any better information.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_AUDIO_DEVICE_APP_NAME "SDL_AUDIO_DEVICE_APP_NAME"

/**
 *  \brief Specify an application name for an audio device.
 *
 * Some audio backends (such as PulseAudio) allow you to describe your audio
 * stream. Among other things, this description might show up in a system
 * control panel that lets the user adjust the volume on specific audio
 * streams instead of using one giant master volume slider.
 *
 * This hints lets you transmit that information to the OS. The contents of
 * this hint are used while opening an audio device. You should use a string
 * that describes your what your program is playing ("audio stream" is
 * probably sufficient in many cases, but this could be useful for something
 * like "team chat" if you have a headset playing VoIP audio separately).
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: "audio stream" or something similar.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_AUDIO_DEVICE_STREAM_NAME "SDL_AUDIO_DEVICE_STREAM_NAME"

/**
 *  \brief Specify an application role for an audio device.
 *
 * Some audio backends (such as Pipewire) allow you to describe the role of
 * your audio stream. Among other things, this description might show up in
 * a system control panel or software for displaying and manipulating media
 * playback/capture graphs.
 *
 * This hints lets you transmit that information to the OS. The contents of
 * this hint are used while opening an audio device. You should use a string
 * that describes your what your program is playing (Game, Music, Movie,
 * etc...).
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: "Game" or something similar.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_AUDIO_DEVICE_STREAM_ROLE "SDL_AUDIO_DEVICE_STREAM_ROLE"

/**
 *  \brief  A variable controlling speed/quality tradeoff of audio resampling.
 *
 *  If available, SDL can use libsamplerate ( http://www.mega-nerd.com/SRC/ )
 *  to handle audio resampling. There are different resampling modes available
 *  that produce different levels of quality, using more CPU.
 *
 *  If this hint isn't specified to a valid setting, or libsamplerate isn't
 *  available, SDL will use the default, internal resampling algorithm.
 *
 *  Note that this is currently only applicable to resampling audio that is
 *  being written to a device for playback or audio being read from a device
 *  for capture. SDL_AudioCVT always uses the default resampler (although this
 *  might change for SDL 2.1).
 *
 *  This hint is currently only checked at audio subsystem initialization.
 *
 *  This variable can be set to the following values:
 *
 *    "0" or "default" - Use SDL's internal resampling (Default when not set - low quality, fast)
 *    "1" or "fast"    - Use fast, slightly higher quality resampling, if available
 *    "2" or "medium"  - Use medium quality resampling, if available
 *    "3" or "best"    - Use high quality resampling, if available
 */
#define SDL_HINT_AUDIO_RESAMPLING_MODE   "SDL_AUDIO_RESAMPLING_MODE"

/**
 *  \brief  A variable controlling whether SDL updates joystick state when getting input events
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - You'll call SDL_JoystickUpdate() manually
 *    "1"     - SDL will automatically call SDL_JoystickUpdate() (default)
 *
 *  This hint can be toggled on and off at runtime.
 */
#define SDL_HINT_AUTO_UPDATE_JOYSTICKS  "SDL_AUTO_UPDATE_JOYSTICKS"

/**
 *  \brief  A variable controlling whether SDL updates sensor state when getting input events
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - You'll call SDL_SensorUpdate() manually
 *    "1"     - SDL will automatically call SDL_SensorUpdate() (default)
 *
 *  This hint can be toggled on and off at runtime.
 */
#define SDL_HINT_AUTO_UPDATE_SENSORS    "SDL_AUTO_UPDATE_SENSORS"

/**
 *  \brief Prevent SDL from using version 4 of the bitmap header when saving BMPs.
 *
 * The bitmap header version 4 is required for proper alpha channel support and
 * SDL will use it when required. Should this not be desired, this hint can
 * force the use of the 40 byte header version which is supported everywhere.
 *
 * The variable can be set to the following values:
 *   "0"       - Surfaces with a colorkey or an alpha channel are saved to a
 *               32-bit BMP file with an alpha mask. SDL will use the bitmap
 *               header version 4 and set the alpha mask accordingly.
 *   "1"       - Surfaces with a colorkey or an alpha channel are saved to a
 *               32-bit BMP file without an alpha mask. The alpha channel data
 *               will be in the file, but applications are going to ignore it.
 *
 * The default value is "0".
 */
#define SDL_HINT_BMP_SAVE_LEGACY_FORMAT "SDL_BMP_SAVE_LEGACY_FORMAT"

/**
 *  \brief Override for SDL_GetDisplayUsableBounds()
 *
 *  If set, this hint will override the expected results for
 *  SDL_GetDisplayUsableBounds() for display index 0. Generally you don't want
 *  to do this, but this allows an embedded system to request that some of the
 *  screen be reserved for other uses when paired with a well-behaved
 *  application.
 *
 *  The contents of this hint must be 4 comma-separated integers, the first
 *  is the bounds x, then y, width and height, in that order.
 */
#define SDL_HINT_DISPLAY_USABLE_BOUNDS "SDL_DISPLAY_USABLE_BOUNDS"

/**
 *  \brief Disable giving back control to the browser automatically
 *  when running with asyncify
 *
 * With -s ASYNCIFY, SDL2 calls emscripten_sleep during operations
 * such as refreshing the screen or polling events.
 *
 * This hint only applies to the emscripten platform
 *
 * The variable can be set to the following values:
 *    "0"       - Disable emscripten_sleep calls (if you give back browser control manually or use asyncify for other purposes)
 *    "1"       - Enable emscripten_sleep calls (the default)
 */
#define SDL_HINT_EMSCRIPTEN_ASYNCIFY   "SDL_EMSCRIPTEN_ASYNCIFY"

/**
 *  \brief override the binding element for keyboard inputs for Emscripten builds
 *
 * This hint only applies to the emscripten platform
 *
 * The variable can be one of
 *    "#window"      - The javascript window object (this is the default)
 *    "#document"    - The javascript document object
 *    "#screen"      - the javascript window.screen object
 *    "#canvas"      - the WebGL canvas element
 *    any other string without a leading # sign applies to the element on the page with that ID.
 */
#define SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT   "SDL_EMSCRIPTEN_KEYBOARD_ELEMENT"

/**
 *  \brief  A variable that controls whether Steam Controllers should be exposed using the SDL joystick and game controller APIs
 *
 *  The variable can be set to the following values:
 *    "0"       - Do not scan for Steam Controllers
 *    "1"       - Scan for Steam Controllers (the default)
 *
 *  The default value is "1".  This hint must be set before initializing the joystick subsystem.
 */
#define SDL_HINT_ENABLE_STEAM_CONTROLLERS "SDL_ENABLE_STEAM_CONTROLLERS"

/**
 *  \brief  A variable controlling whether SDL logs all events pushed onto its internal queue.
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - Don't log any events (default)
 *    "1"     - Log all events except mouse and finger motion, which are pretty spammy.
 *    "2"     - Log all events.
 *
 *  This is generally meant to be used to debug SDL itself, but can be useful
 *  for application developers that need better visibility into what is going
 *  on in the event queue. Logged events are sent through SDL_Log(), which
 *  means by default they appear on stdout on most platforms or maybe
 *  OutputDebugString() on Windows, and can be funneled by the app with
 *  SDL_LogSetOutputFunction(), etc.
 *
 *  This hint can be toggled on and off at runtime, if you only need to log
 *  events for a small subset of program execution.
 */
#define SDL_HINT_EVENT_LOGGING   "SDL_EVENT_LOGGING"

/**
 *  \brief  A variable controlling how 3D acceleration is used to accelerate the SDL screen surface.
 *
 *  SDL can try to accelerate the SDL screen surface by using streaming
 *  textures with a 3D rendering engine.  This variable controls whether and
 *  how this is done.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable 3D acceleration
 *    "1"       - Enable 3D acceleration, using the default renderer.
 *    "X"       - Enable 3D acceleration, using X where X is one of the valid rendering drivers.  (e.g. "direct3d", "opengl", etc.)
 *
 *  By default SDL tries to make a best guess for each platform whether
 *  to use acceleration or not.
 */
#define SDL_HINT_FRAMEBUFFER_ACCELERATION   "SDL_FRAMEBUFFER_ACCELERATION"

/**
 *  \brief  A variable that lets you manually hint extra gamecontroller db entries.
 *
 *  The variable should be newline delimited rows of gamecontroller config data, see SDL_gamecontroller.h
 *
 *  This hint must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 *  You can update mappings after the system is initialized with SDL_GameControllerMappingForGUID() and SDL_GameControllerAddMapping()
 */
#define SDL_HINT_GAMECONTROLLERCONFIG "SDL_GAMECONTROLLERCONFIG"

/**
 *  \brief  A variable that lets you provide a file with extra gamecontroller db entries.
 *
 *  The file should contain lines of gamecontroller config data, see SDL_gamecontroller.h
 *
 *  This hint must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 *  You can update mappings after the system is initialized with SDL_GameControllerMappingForGUID() and SDL_GameControllerAddMapping()
 */
#define SDL_HINT_GAMECONTROLLERCONFIG_FILE "SDL_GAMECONTROLLERCONFIG_FILE"

/**
 *  \brief  A variable that overrides the automatic controller type detection
 *
 *  The variable should be comma separated entries, in the form: VID/PID=type
 *
 *  The VID and PID should be hexadecimal with exactly 4 digits, e.g. 0x00fd
 *
 *  The type should be one of:
 *      Xbox360
 *      XboxOne
 *      PS3
 *      PS4
 *      PS5
 *      SwitchPro
 *
 *  This hint affects what driver is used, and must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 */
#define SDL_HINT_GAMECONTROLLERTYPE "SDL_GAMECONTROLLERTYPE"

/**
 *  \brief  A variable containing a list of devices to skip when scanning for game controllers.
 *
 *  The format of the string is a comma separated list of USB VID/PID pairs
 *  in hexadecimal form, e.g.
 *
 *      0xAAAA/0xBBBB,0xCCCC/0xDDDD
 *
 *  The variable can also take the form of @file, in which case the named
 *  file will be loaded and interpreted as the value of the variable.
 */
#define SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES "SDL_GAMECONTROLLER_IGNORE_DEVICES"

/**
 *  \brief  If set, all devices will be skipped when scanning for game controllers except for the ones listed in this variable.
 *
 *  The format of the string is a comma separated list of USB VID/PID pairs
 *  in hexadecimal form, e.g.
 *
 *      0xAAAA/0xBBBB,0xCCCC/0xDDDD
 *
 *  The variable can also take the form of @file, in which case the named
 *  file will be loaded and interpreted as the value of the variable.
 */
#define SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT "SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT"

/**
 *  \brief  If set, game controller face buttons report their values according to their labels instead of their positional layout.
 * 
 *  For example, on Nintendo Switch controllers, normally you'd get:
 *
 *      (Y)
 *  (X)     (B)
 *      (A)
 *
 *  but if this hint is set, you'll get:
 *
 *      (X)
 *  (Y)     (A)
 *      (B)
 *
 *  The variable can be set to the following values:
 *    "0"       - Report the face buttons by position, as though they were on an Xbox controller.
 *    "1"       - Report the face buttons by label instead of position
 *
 *  The default value is "1".  This hint may be set at any time.
 */
#define SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS "SDL_GAMECONTROLLER_USE_BUTTON_LABELS"

/**
 *  \brief  A variable controlling whether grabbing input grabs the keyboard
 *
 *  This variable can be set to the following values:
 *    "0"       - Grab will affect only the mouse
 *    "1"       - Grab will affect mouse and keyboard
 *
 *  By default SDL will not grab the keyboard so system shortcuts still work.
 */
#define SDL_HINT_GRAB_KEYBOARD              "SDL_GRAB_KEYBOARD"

/**
 *  \brief  A variable controlling whether the idle timer is disabled on iOS.
 *
 *  When an iOS app does not receive touches for some time, the screen is
 *  dimmed automatically. For games where the accelerometer is the only input
 *  this is problematic. This functionality can be disabled by setting this
 *  hint.
 *
 *  As of SDL 2.0.4, SDL_EnableScreenSaver() and SDL_DisableScreenSaver()
 *  accomplish the same thing on iOS. They should be preferred over this hint.
 *
 *  This variable can be set to the following values:
 *    "0"       - Enable idle timer
 *    "1"       - Disable idle timer
 */
#define SDL_HINT_IDLE_TIMER_DISABLED "SDL_IOS_IDLE_TIMER_DISABLED"

/**
 * \brief A variable to control whether certain IMEs should handle text editing internally instead of sending SDL_TEXTEDITING events.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL_TEXTEDITING events are sent, and it is the application's
 *               responsibility to render the text from these events and 
 *               differentiate it somehow from committed text. (default)
 *   "1"       - If supported by the IME then SDL_TEXTEDITING events are not sent, 
 *               and text that is being composed will be rendered in its own UI.
 */
#define SDL_HINT_IME_INTERNAL_EDITING "SDL_IME_INTERNAL_EDITING"

/**
 * \brief  A variable controlling whether the home indicator bar on iPhone X
 *         should be hidden.
 *
 *  This variable can be set to the following values:
 *    "0"       - The indicator bar is not hidden (default for windowed applications)
 *    "1"       - The indicator bar is hidden and is shown when the screen is touched (useful for movie playback applications)
 *    "2"       - The indicator bar is dim and the first swipe makes it visible and the second swipe performs the "home" action (default for fullscreen applications)
 */
#define SDL_HINT_IOS_HIDE_HOME_INDICATOR "SDL_IOS_HIDE_HOME_INDICATOR"

/**
 *  \brief  A variable that lets you enable joystick (and gamecontroller) events even when your app is in the background.
 *
 *  The variable can be set to the following values:
 *    "0"       - Disable joystick & gamecontroller input events when the
 *                application is in the background.
 *    "1"       - Enable joystick & gamecontroller input events when the
 *                application is in the background.
 *
 *  The default value is "0".  This hint may be set at any time.
 */
#define SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS "SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS"

/**
 *  \brief  A variable controlling whether the HIDAPI joystick drivers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI drivers are not used
 *    "1"       - HIDAPI drivers are used (the default)
 *
 *  This variable is the default for all drivers, but can be overridden by the hints for specific drivers below.
 */
#define SDL_HINT_JOYSTICK_HIDAPI "SDL_JOYSTICK_HIDAPI"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for Nintendo GameCube controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_GAMECUBE "SDL_JOYSTICK_HIDAPI_GAMECUBE"

 /**
  *  \brief  A variable controlling whether Switch Joy-Cons should be treated the same as Switch Pro Controllers when using the HIDAPI driver.
  *
  *  This variable can be set to the following values:
  *    "0"       - basic Joy-Con support with no analog input (the default)
  *    "1"       - Joy-Cons treated as half full Pro Controllers with analog inputs and sensors
  *
  *  This does not combine Joy-Cons into a single controller. That's up to the user.
  */
#define SDL_HINT_JOYSTICK_HIDAPI_JOY_CONS "SDL_JOYSTICK_HIDAPI_JOY_CONS"

 /**
  *  \brief  A variable controlling whether the HIDAPI driver for Amazon Luna controllers connected via Bluetooth should be used.
  *
  *  This variable can be set to the following values:
  *    "0"       - HIDAPI driver is not used
  *    "1"       - HIDAPI driver is used
  *
  *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
  */
#define SDL_HINT_JOYSTICK_HIDAPI_LUNA "SDL_JOYSTICK_HIDAPI_LUNA"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for PS4 controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_PS4 "SDL_JOYSTICK_HIDAPI_PS4"

/**
 *  \brief  A variable controlling whether extended input reports should be used for PS4 controllers when using the HIDAPI driver.
 *
 *  This variable can be set to the following values:
 *    "0"       - extended reports are not enabled (the default)
 *    "1"       - extended reports
 *
 *  Extended input reports allow rumble on Bluetooth PS4 controllers, but
 *  break DirectInput handling for applications that don't use SDL.
 *
 *  Once extended reports are enabled, they can not be disabled without
 *  power cycling the controller.
 *
 *  For compatibility with applications written for versions of SDL prior
 *  to the introduction of PS5 controller support, this value will also
 *  control the state of extended reports on PS5 controllers when the
 *  SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE hint is not explicitly set.
 */
#define SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE "SDL_JOYSTICK_HIDAPI_PS4_RUMBLE"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for PS5 controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_PS5 "SDL_JOYSTICK_HIDAPI_PS5"

/**
 *  \brief  A variable controlling whether the player LEDs should be lit to indicate which player is associated with a PS5 controller.
 *
 *  This variable can be set to the following values:
 *    "0"       - player LEDs are not enabled
 *    "1"       - player LEDs are enabled (the default)
 */
#define SDL_HINT_JOYSTICK_HIDAPI_PS5_PLAYER_LED "SDL_JOYSTICK_HIDAPI_PS5_PLAYER_LED"

/**
 *  \brief  A variable controlling whether extended input reports should be used for PS5 controllers when using the HIDAPI driver.
 *
 *  This variable can be set to the following values:
 *    "0"       - extended reports are not enabled (the default)
 *    "1"       - extended reports
 *
 *  Extended input reports allow rumble on Bluetooth PS5 controllers, but
 *  break DirectInput handling for applications that don't use SDL.
 *
 *  Once extended reports are enabled, they can not be disabled without
 *  power cycling the controller.
 *
 *  For compatibility with applications written for versions of SDL prior
 *  to the introduction of PS5 controller support, this value defaults to
 *  the value of SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE.
 */
#define SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE "SDL_JOYSTICK_HIDAPI_PS5_RUMBLE"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for Google Stadia controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_STADIA "SDL_JOYSTICK_HIDAPI_STADIA"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for Steam Controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_STEAM "SDL_JOYSTICK_HIDAPI_STEAM"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for Nintendo Switch controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_SWITCH "SDL_JOYSTICK_HIDAPI_SWITCH"

/**
 *  \brief  A variable controlling whether the Home button LED should be turned on when a Nintendo Switch controller is opened
 *
 *  This variable can be set to the following values:
 *    "0"       - home button LED is left off
 *    "1"       - home button LED is turned on (the default)
 */
#define SDL_HINT_JOYSTICK_HIDAPI_SWITCH_HOME_LED "SDL_JOYSTICK_HIDAPI_SWITCH_HOME_LED"

/**
 *  \brief  A variable controlling whether the HIDAPI driver for XBox controllers should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - HIDAPI driver is not used
 *    "1"       - HIDAPI driver is used
 *
 *  The default is "0" on Windows, otherwise the value of SDL_HINT_JOYSTICK_HIDAPI
 */
#define SDL_HINT_JOYSTICK_HIDAPI_XBOX   "SDL_JOYSTICK_HIDAPI_XBOX"

 /**
  *  \brief  A variable controlling whether the RAWINPUT joystick drivers should be used for better handling XInput-capable devices.
  *
  *  This variable can be set to the following values:
  *    "0"       - RAWINPUT drivers are not used
  *    "1"       - RAWINPUT drivers are used (the default)
  *
  */
#define SDL_HINT_JOYSTICK_RAWINPUT "SDL_JOYSTICK_RAWINPUT"

 /**
  *  \brief  A variable controlling whether the RAWINPUT driver should pull correlated data from XInput.
  *
  *  This variable can be set to the following values:
  *    "0"       - RAWINPUT driver will only use data from raw input APIs
  *    "1"       - RAWINPUT driver will also pull data from XInput, providing
  *                better trigger axes, guide button presses, and rumble support
  *                for Xbox controllers
  *
  *  The default is "1".  This hint applies to any joysticks opened after setting the hint.
  */
#define SDL_HINT_JOYSTICK_RAWINPUT_CORRELATE_XINPUT   "SDL_JOYSTICK_RAWINPUT_CORRELATE_XINPUT"

 /**
  *  \brief  A variable controlling whether a separate thread should be used
  *          for handling joystick detection and raw input messages on Windows
  *
  *  This variable can be set to the following values:
  *    "0"       - A separate thread is not used (the default)
  *    "1"       - A separate thread is used for handling raw input messages
  *
  */
#define SDL_HINT_JOYSTICK_THREAD "SDL_JOYSTICK_THREAD"

/**
 * \brief Determines whether SDL enforces that DRM master is required in order
 *        to initialize the KMSDRM video backend.
 *
 * The DRM subsystem has a concept of a "DRM master" which is a DRM client that
 * has the ability to set planes, set cursor, etc. When SDL is DRM master, it
 * can draw to the screen using the SDL rendering APIs. Without DRM master, SDL
 * is still able to process input and query attributes of attached displays,
 * but it cannot change display state or draw to the screen directly.
 *
 * In some cases, it can be useful to have the KMSDRM backend even if it cannot
 * be used for rendering. An app may want to use SDL for input processing while
 * using another rendering API (such as an MMAL overlay on Raspberry Pi) or
 * using its own code to render to DRM overlays that SDL doesn't support.
 *
 * This hint must be set before initializing the video subsystem.
 *
 * This variable can be set to the following values:
 *    "0"       - SDL will allow usage of the KMSDRM backend without DRM master
 *    "1"       - SDL Will require DRM master to use the KMSDRM backend (default)
 */
#define SDL_HINT_KMSDRM_REQUIRE_DRM_MASTER      "SDL_KMSDRM_REQUIRE_DRM_MASTER"

 /**
  *  \brief  A variable controlling whether joysticks on Linux adhere to their HID-defined deadzones or return unfiltered values.
  *
  *  This variable can be set to the following values:
  *    "0"       - Return unfiltered joystick axis values (the default)
  *    "1"       - Return axis values with deadzones taken into account
  */
#define SDL_HINT_LINUX_JOYSTICK_DEADZONES "SDL_LINUX_JOYSTICK_DEADZONES"

/**
*  \brief  When set don't force the SDL app to become a foreground process
*
*  This hint only applies to Mac OS X.
*
*/
#define SDL_HINT_MAC_BACKGROUND_APP    "SDL_MAC_BACKGROUND_APP"

/**
 *  \brief A variable that determines whether ctrl+click should generate a right-click event on Mac
 *
 *  If present, holding ctrl while left clicking will generate a right click
 *  event when on Mac.
 */
#define SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK "SDL_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK"

/**
 *  \brief  A variable setting the double click radius, in pixels.
 */
#define SDL_HINT_MOUSE_DOUBLE_CLICK_RADIUS    "SDL_MOUSE_DOUBLE_CLICK_RADIUS"

/**
 *  \brief  A variable setting the double click time, in milliseconds.
 */
#define SDL_HINT_MOUSE_DOUBLE_CLICK_TIME    "SDL_MOUSE_DOUBLE_CLICK_TIME"

/**
 *  \brief Allow mouse click events when clicking to focus an SDL window
 *
 *  This variable can be set to the following values:
 *    "0"       - Ignore mouse clicks that activate a window
 *    "1"       - Generate events for mouse clicks that activate a window
 *
 *  By default SDL will ignore mouse clicks that activate a window
 */
#define SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH "SDL_MOUSE_FOCUS_CLICKTHROUGH"

/**
 *  \brief  A variable setting the speed scale for mouse motion, in floating point, when the mouse is not in relative mode
 */
#define SDL_HINT_MOUSE_NORMAL_SPEED_SCALE    "SDL_MOUSE_NORMAL_SPEED_SCALE"

/**
 *  \brief  A variable controlling whether relative mouse mode is implemented using mouse warping
 *
 *  This variable can be set to the following values:
 *    "0"       - Relative mouse mode uses raw input
 *    "1"       - Relative mouse mode uses mouse warping
 *
 *  By default SDL will use raw input for relative mouse mode
 */
#define SDL_HINT_MOUSE_RELATIVE_MODE_WARP    "SDL_MOUSE_RELATIVE_MODE_WARP"

/**
 *  \brief  A variable controlling whether relative mouse motion is affected by renderer scaling
 *
 *  This variable can be set to the following values:
 *    "0"       - Relative motion is unaffected by DPI or renderer's logical size
 *    "1"       - Relative motion is scaled according to DPI scaling and logical size
 *
 *  By default relative mouse deltas are affected by DPI and renderer scaling
 */
#define SDL_HINT_MOUSE_RELATIVE_SCALING "SDL_MOUSE_RELATIVE_SCALING"

/**
 *  \brief  A variable setting the scale for mouse motion, in floating point, when the mouse is in relative mode
 */
#define SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE    "SDL_MOUSE_RELATIVE_SPEED_SCALE"

/**
 *  \brief  A variable controlling whether mouse events should generate synthetic touch events
 *
 *  This variable can be set to the following values:
 *    "0"       - Mouse events will not generate touch events (default for desktop platforms)
 *    "1"       - Mouse events will generate touch events (default for mobile platforms, such as Android and iOS)
 */
#define SDL_HINT_MOUSE_TOUCH_EVENTS    "SDL_MOUSE_TOUCH_EVENTS"

/**
 *  \brief Tell SDL not to catch the SIGINT or SIGTERM signals.
 *
 * This hint only applies to Unix-like platforms, and should set before
 * any calls to SDL_Init()
 *
 * The variable can be set to the following values:
 *   "0"       - SDL will install a SIGINT and SIGTERM handler, and when it
 *               catches a signal, convert it into an SDL_QUIT event.
 *   "1"       - SDL will not install a signal handler at all.
 */
#define SDL_HINT_NO_SIGNAL_HANDLERS   "SDL_NO_SIGNAL_HANDLERS"

/**
 *  \brief  A variable controlling what driver to use for OpenGL ES contexts.
 *
 *  On some platforms, currently Windows and X11, OpenGL drivers may support
 *  creating contexts with an OpenGL ES profile. By default SDL uses these
 *  profiles, when available, otherwise it attempts to load an OpenGL ES
 *  library, e.g. that provided by the ANGLE project. This variable controls
 *  whether SDL follows this default behaviour or will always load an
 *  OpenGL ES library.
 *
 *  Circumstances where this is useful include
 *  - Testing an app with a particular OpenGL ES implementation, e.g ANGLE,
 *    or emulator, e.g. those from ARM, Imagination or Qualcomm.
 *  - Resolving OpenGL ES function addresses at link time by linking with
 *    the OpenGL ES library instead of querying them at run time with
 *    SDL_GL_GetProcAddress().
 *
 *  Caution: for an application to work with the default behaviour across
 *  different OpenGL drivers it must query the OpenGL ES function
 *  addresses at run time using SDL_GL_GetProcAddress().
 *
 *  This variable is ignored on most platforms because OpenGL ES is native
 *  or not supported.
 *
 *  This variable can be set to the following values:
 *    "0"       - Use ES profile of OpenGL, if available. (Default when not set.)
 *    "1"       - Load OpenGL ES library using the default library names.
 *
 */
#define SDL_HINT_OPENGL_ES_DRIVER   "SDL_OPENGL_ES_DRIVER"

/**
 *  \brief  A variable controlling which orientations are allowed on iOS/Android.
 *
 *  In some circumstances it is necessary to be able to explicitly control
 *  which UI orientations are allowed.
 *
 *  This variable is a space delimited list of the following values:
 *    "LandscapeLeft", "LandscapeRight", "Portrait" "PortraitUpsideDown"
 */
#define SDL_HINT_ORIENTATIONS "SDL_IOS_ORIENTATIONS"

/**
 *  \brief Override for SDL_GetPreferredLocales()
 *
 *  If set, this will be favored over anything the OS might report for the
 *  user's preferred locales. Changing this hint at runtime will not generate
 *  a SDL_LOCALECHANGED event (but if you can change the hint, you can push
 *  your own event, if you want).
 *
 *  The format of this hint is a comma-separated list of language and locale,
 *  combined with an underscore, as is a common format: "en_GB". Locale is
 *  optional: "en". So you might have a list like this: "en_GB,jp,es_PT"
 */
#define SDL_HINT_PREFERRED_LOCALES "SDL_PREFERRED_LOCALES"

/**
 *  \brief  A variable describing the content orientation on QtWayland-based platforms.
 *
 *  On QtWayland platforms, windows are rotated client-side to allow for custom
 *  transitions. In order to correctly position overlays (e.g. volume bar) and
 *  gestures (e.g. events view, close/minimize gestures), the system needs to
 *  know in which orientation the application is currently drawing its contents.
 *
 *  This does not cause the window to be rotated or resized, the application
 *  needs to take care of drawing the content in the right orientation (the
 *  framebuffer is always in portrait mode).
 *
 *  This variable can be one of the following values:
 *    "primary" (default), "portrait", "landscape", "inverted-portrait", "inverted-landscape"
 */
#define SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION "SDL_QTWAYLAND_CONTENT_ORIENTATION"

/**
 *  \brief  Flags to set on QtWayland windows to integrate with the native window manager.
 *
 *  On QtWayland platforms, this hint controls the flags to set on the windows.
 *  For example, on Sailfish OS "OverridesSystemGestures" disables swipe gestures.
 *
 *  This variable is a space-separated list of the following values (empty = no flags):
 *    "OverridesSystemGestures", "StaysOnTop", "BypassWindowManager"
 */
#define SDL_HINT_QTWAYLAND_WINDOW_FLAGS "SDL_QTWAYLAND_WINDOW_FLAGS"

/**
 *  \brief  A variable controlling whether the 2D render API is compatible or efficient.
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - Don't use batching to make rendering more efficient.
 *    "1"     - Use batching, but might cause problems if app makes its own direct OpenGL calls.
 *
 *  Up to SDL 2.0.9, the render API would draw immediately when requested. Now
 *  it batches up draw requests and sends them all to the GPU only when forced
 *  to (during SDL_RenderPresent, when changing render targets, by updating a
 *  texture that the batch needs, etc). This is significantly more efficient,
 *  but it can cause problems for apps that expect to render on top of the
 *  render API's output. As such, SDL will disable batching if a specific
 *  render backend is requested (since this might indicate that the app is
 *  planning to use the underlying graphics API directly). This hint can
 *  be used to explicitly request batching in this instance. It is a contract
 *  that you will either never use the underlying graphics API directly, or
 *  if you do, you will call SDL_RenderFlush() before you do so any current
 *  batch goes to the GPU before your work begins. Not following this contract
 *  will result in undefined behavior.
 */
#define SDL_HINT_RENDER_BATCHING  "SDL_RENDER_BATCHING"

/**
 *  \brief  A variable controlling whether to enable Direct3D 11+'s Debug Layer.
 *
 *  This variable does not have any effect on the Direct3D 9 based renderer.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable Debug Layer use
 *    "1"       - Enable Debug Layer use
 *
 *  By default, SDL does not use Direct3D Debug Layer.
 */
#define SDL_HINT_RENDER_DIRECT3D11_DEBUG    "SDL_RENDER_DIRECT3D11_DEBUG"

/**
 *  \brief  A variable controlling whether the Direct3D device is initialized for thread-safe operations.
 *
 *  This variable can be set to the following values:
 *    "0"       - Thread-safety is not enabled (faster)
 *    "1"       - Thread-safety is enabled
 *