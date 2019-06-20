#include "BrushFactory.h"

#include "Pen.h"
#include "Parabola.h"
#include "NullBrush.h"

std::unique_ptr<Brush> BrushFactory::create(BrushStrategy brushStrategy) const
{
	switch (brushStrategy)
	{
	case BrushStrategy::Pen:
		return std::move(std::make_unique<Pen>(Pen()));
		break;
		
	case BrushStrategy::Parabola:
		return std::move(std::make_unique<Parabola>(Parabola()));
		break;

	default:
		return std::move(std::make_unique<NullBrush>(NullBrush()));
		break;
	}
}