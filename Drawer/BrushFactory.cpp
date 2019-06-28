#include "BrushFactory.h"

std::unique_ptr<Brush> BrushFactory::create(BrushStrategy strategy) const
{
	switch (strategy)
	{
	case BrushStrategy::Line:
		return std::move(std::make_unique<Line>(Line()));
		break;

	case BrushStrategy::Parabola:
		return std::move(std::make_unique<Parabola>(Parabola()));
		break;

	case BrushStrategy::Pen:
		return std::move(std::make_unique<Pen>(Pen()));
		break;

	case BrushStrategy::ThickPen:
		return std::move(std::make_unique<ThickPen>(ThickPen()));
		break;

	case BrushStrategy::Rubber:
		return std::move(std::make_unique<Rubber>(Rubber()));
		break;

	default:
		return std::move(std::make_unique<Pen>(Pen()));
		break;
	}
}
