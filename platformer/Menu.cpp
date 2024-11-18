#include "Menu.h"
#include "Utility.h"


Menu::~Menu()
{
	Mix_FreeMusic(m_game_state.bgm);
	Mix_FreeChunk(m_game_state.jump_sfx);
}