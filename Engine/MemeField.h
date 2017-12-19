#pragma once
#include "Graphics.h"

class MemeField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed
		};
	public:
		void SpwanMeme();
		bool HasMeme()const;
	private:
		State state = State::Hidden;
		bool hasMeme = false;
	};
public:
	MemeField(int nMemes);
	void Draw(Graphics& gfx)const;
private:
	Tile & TileAt(const Vei2& gridPos);
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile field[width * height];
};