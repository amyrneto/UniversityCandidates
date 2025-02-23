#include "pch.h"
#include "ExportedTypes.h"

void RootData::AppendData(const RootData& other)
{
	candidates.insert(candidates.end(), other.candidates.begin(), other.candidates.end());
}

void RootData::Clear()
{
	candidates.clear();
}
