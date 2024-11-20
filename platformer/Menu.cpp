#include "Menu.h"
#include "Utility.h"


#define MENU_WIDTH 20
#define MENU_HEIGHT 8

unsigned int MENU_DATA[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void Menu::initialise()
{
	m_game_state.bgm = Mix_LoadMUS("assets/bgm.mp3");
	m_game_state.jump_sfx = Mix_LoadWAV("assets/jump.wav");

	m_game_state.next_scene_id = -1;

    GLuint map_texture_id = Utility::load_texture("assets/world_tileset2.png");
    m_game_state.map = new Map(MENU_WIDTH, MENU_HEIGHT, MENU_DATA, map_texture_id, 1.0f, 22, 11);
}

Menu::~Menu()
{
    delete[]  m_game_state.enemies;
    delete    m_game_state.player;
    delete    m_game_state.map;

	Mix_FreeMusic(m_game_state.bgm);
	Mix_FreeChunk(m_game_state.jump_sfx);
}

void Menu::update(float delta_time)
{
	m_game_state.player->update(delta_time, m_game_state.player, m_game_state.enemies, 1, m_game_state.map);
}

void Menu::render(ShaderProgram* program)
{
    GLuint text_texture_id = Utility::load_texture("assets/font1.png");

    Utility::draw_text(program, text_texture_id, "PLATFORMER", 1.0f, -0.1f, glm::vec3(10.0f, -9.0f, 0.0f));
    Utility::draw_text(program, text_texture_id, "PRESS ENTER TO START", 1.0f, -0.1f, glm::vec3(4.0f, -12.0f, 0.0f));
}