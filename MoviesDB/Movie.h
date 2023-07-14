#pragma once
using namespace System;

ref class Movie {
public:
	String^ Title;
	String^ PosterPath;
	String^ Genre;
	String^ Annotation;
	DateTime RealeaseDate;
	int Rating;
	Movie ^Next;
	Movie(String^ title, String^ posterpath, String^ genre, String^ annotation, DateTime realesadate, int rating)
	{
		this->Title = title;
		this->Genre = genre;
		this->PosterPath = posterpath;
		this->Annotation= annotation;
		RealeaseDate = realesadate;
		Rating = rating;
		Next = nullptr;
	}
};


