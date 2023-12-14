#pragma once

int N = 20;
const int SIZE = 16;
const int title = 48;
const int border = 15;
int w = SIZE * N;

float timer = 0, interval = 0.3, speed = 0.3;
int speedup = N / 5;
int score = 0;

bool startFlag = false;

const string _BACKGROUND = "images/background.png";
const string _SNAKE = "images/snake.png";
const string _APPLE = "images/apple.png";
const string _FONT = "arial.ttf";
const string _EAT_SOUND = "sounds/eatApple.wav";
const string _LEFT_PRESS_SOUND = "sounds/LeftPress.wav";
const string _RIGHT_PRESS_SOUND = "sounds/RightPress.wav";
const string _UP_PRESS_SOUND = "sounds/UpPress.wav";
const string _DOWN_PRESS_SOUND = "sounds/DownPress.wav";

RenderWindow window;

Event event;

Texture background, snakeColor, appleColor;

Sprite s_backgound;
Sprite s_snake;
Sprite s_apple;

Font font;
Text TitleText, StartText, QuitText, TenText, TwentyText, ThirtyText, ScoreText;

SoundBuffer eatSound_Buffer;
SoundBuffer LeftPress_Buffer, RightPress_Buffer, UpPress_Buffer, DownPress_Buffer;

Sound eatSound;
Sound LeftPress, RightPress, UpPress, DownPress;

void SetupTitleText(Text& text, Font& font, string str, int fontsize, Color fillcolor) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(fontsize);
    text.setFillColor(fillcolor);
}