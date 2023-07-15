#pragma once

#include "Movie.h"
using namespace System::Collections::Generic;

ref class MovieLinkedList
{
private:
	Movie^ head;
	Movie^ tail;
public:
	MovieLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	Movie^ Head(); 
	Movie^ Tail(); 
	bool ReadBase(System::String^ path);
	bool SaveBase(System::String^ path);
	void AddMovie(Movie^ movie); 
	void DeleteMovie(int MovIndex); 
	void EditMovie(Movie^ movie, System::String^ _title, System::String^ _posterPath,
		System::String^ _annotation, System::String^ _genre, int _raiting, System::DateTime _realeaseDate);
	List<Movie^>^ Find(System::String^ title);
	List<Movie^>^ Find(int raitingFrom, int raitingTo); 
	List<Movie^>^ FindbyGenre(System::String^ genre);
	List<Movie^>^ GetMovies();
};

