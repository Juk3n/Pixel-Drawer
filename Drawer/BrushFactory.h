#pragma once

#include "Brush.h"

#include <memory>

#include "Brush.h"
#include "Pen.h"
#include "ThickPen.h"
#include "Line.h"
#include "Rubber.h"

class BrushFactory
{
public:
	enum class BrushStrategy
	{
		NullBrush,
		Pen,
		ThickPen,
		Rubber,
		Line 
	};

	std::unique_ptr<Brush> create(BrushStrategy) const;
};

