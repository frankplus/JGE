/*******************************************************
 * 
 * Copyright (C) 2019 Francesco Pham (pham.francesco@gmail.com)
 * Copyright (c) 2007 James Hui (a.k.a. Dr.Watson) <jhkhui@gmail.com>
 * 
 *******************************************************/
#ifndef _FILE_SYSTEM_H_
#define _FILE_SYSTEM_H_

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class JFileSystem
{
public:

	//////////////////////////////////////////////////////////////////////////
	/// Get the singleton instance
	///
	//////////////////////////////////////////////////////////////////////////
	static JFileSystem* GetInstance();

	static void Destroy();

	
	//////////////////////////////////////////////////////////////////////////
	/// Open file for reading.
	/// 
	//////////////////////////////////////////////////////////////////////////
	bool OpenFile(const string &filename);

	//////////////////////////////////////////////////////////////////////////
	/// Read data from file.
	/// 
	/// @param buffer - Buffer for reading.
	/// @param size - Number of bytes to read.
	/// 
	/// @return Number of bytes read.
	/// 
	//////////////////////////////////////////////////////////////////////////
	int ReadFile(void *buffer, int size);

	//////////////////////////////////////////////////////////////////////////
	/// Get size of file.
	/// 
	//////////////////////////////////////////////////////////////////////////
	int GetFileSize();

	//////////////////////////////////////////////////////////////////////////
	/// Close file.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void CloseFile();

	//////////////////////////////////////////////////////////////////////////
	/// Set root for all the following file operations
	/// 
	/// @resourceRoot - New root.
	/// 
	//////////////////////////////////////////////////////////////////////////
	void SetResourceRoot(const string& resourceRoot);

protected:
	JFileSystem();
	~JFileSystem();

private:
	static JFileSystem* mInstance;

	string mResourceRoot;
	char *mPassword;

	FILE *mFile;
	int mFileSize;

};

#endif
