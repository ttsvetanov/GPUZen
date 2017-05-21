/*

Copyright 2013,2014 Sergio Ruiz, Benjamin Hernandez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

In case you, or any of your employees or students, publish any article or
other material resulting from the use of this  software, that publication
must cite the following references:

Sergio Ruiz, Benjamin Hernandez, Adriana Alvarado, and Isaac Rudomin. 2013.
Reducing Memory Requirements for Diverse Animated Crowds. In Proceedings of
Motion on Games (MIG '13). ACM, New York, NY, USA, , Article 55 , 10 pages.
DOI: http://dx.doi.org/10.1145/2522628.2522901

Sergio Ruiz and Benjamin Hernandez. 2015. A Parallel Solver for Markov Decision Process
in Crowd Simulations. Fourteenth Mexican International Conference on Artificial
Intelligence (MICAI), Cuernavaca, 2015, pp. 107-116.
DOI: 10.1109/MICAI.2015.23

*/

#pragma once
#include <tinyxml.h>

#include "cMacros.h"
#include "cLogManager.h"

#ifndef __XML_PARSER
#define __XML_PARSER

class XmlParser
{
public:
	XmlParser( LogManager* log_manager, char* _pFilename );
	~XmlParser( void );

	bool			init					( void						);
	char*			getElement				( TiXmlNode*	pParent,
											  char*			name,
											  char*			currname	);
	unsigned int	getUI					( char*			name		);
	unsigned long	getUL					( char*			name		);
	char*			getC					( char*			name		);
	float			getF					( char*			name		);
	bool			getB					( char*			name		);
	void			dump					( void						);
	TiXmlDocument*	getDoc					( void						);
private:
	TiXmlDocument*	doc;
	LogManager*		log_manager;
private:
	void			dump_to_stdout			( TiXmlNode*	pParent,
											  unsigned int	indent = 0	);
	const char*		getIndent				( unsigned int	numIndents	);
	const char*		getIndentAlt			( unsigned int	numIndents	);
	int				dump_attribs_to_stdout	( TiXmlElement* pElement,
											  unsigned int	indent		);

	char*			pFilename;
};

#endif
