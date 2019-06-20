#pragma once

#include <memory>

#include "Brush.h"

class BrushFactory
{
public:
	enum class BrushStrategy
	{
		Pen,
		Parabola,
		NullBrush
	};

	std::unique_ptr<Brush> create(BrushStrategy) const;
};

