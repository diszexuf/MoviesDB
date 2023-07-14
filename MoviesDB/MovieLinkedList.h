#pragma once

#include "Movie.h"
using namespace System;
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
	bool ReadBase(String^ path); 
	bool SaveBase(String^ path); 
	void AddMovie(Movie^ movie); 
	void DeleteMovie(int MovIndex); 
	void EditMovie(Movie^ movie, String^ _title, String^ _posterPath, 
		String^ _annotation, String^ _genre, int _raiting, DateTime _realeaseDate);
	List<Movie^>^ Find(String^ title); 
	List<Movie^>^ Find(int raitingFrom, int raitingTo); 
	List<Movie^>^ FindbyGenre(String^ genre); 
};

