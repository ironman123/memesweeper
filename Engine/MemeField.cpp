#include "MemeField.h"
#include <assert.h>
#include <random>
#include "Vei2.h"

void MemeField::Tile::SpwanMeme()
{
	assert(!hasMeme);
	hasMeme = true;
}

bool MemeField::Tile::HasMeme() const
{
	return hasMeme;
}

MemeField::MemeField(int nMemes)
{
	assert(nMemes > 0 && nMemes < width * height);
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, width - 1);
	std::uniform_int_distribution<int> yDist(0, height - 1);

	for (int nSpawned = 0; nSpawned < nMemes; nSpawned++)
	{
		Vei2 spwanPos;
		do
		{
			spwanPos = { xDist(rng),yDist(rng) };
		} while (TileAt(spwanPos).HasMeme());
		
		TileAt(spwanPos).SpwanMeme();
	}
}

MemeField::Tile & MemeField::TileAt(const Vei2 & gridPos)
{
	return field[gridPos.y * width + gridPos.x];
}
