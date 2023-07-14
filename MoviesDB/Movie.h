#pragma once

ref class Movie {
public:
	System::String^ Title;
	System::String^ PosterPath;
	System::String^ Genre;
	System::String^ Annotation;
	System::DateTime RealeaseDate;
	int Rating;
	Movie ^Next;
	Movie(System::String^ title, System::String^ posterpath, System::String^ genre, 
		System::String^ annotation, System::DateTime realesadate, int rating)
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


