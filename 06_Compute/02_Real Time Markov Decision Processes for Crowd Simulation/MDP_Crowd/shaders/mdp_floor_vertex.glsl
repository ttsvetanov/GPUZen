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
#version 130
#extension GL_ARB_texture_rectangle : require

uniform sampler2DRect policy;
uniform sampler2DRect density;

uniform float fbo_width;
uniform float fbo_height;
uniform float policy_width;
uniform float policy_height;

varying float level;
varying float intensity;
varying vec2 policoord;

void main()
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	vec2 texcoord;
	policoord.x = policy_width  * gl_TexCoord[0].s / fbo_width;
	policoord.y = policy_height * gl_TexCoord[0].t / fbo_height;
	level = texture2DRect( policy, policoord ).x;
	intensity = texture2DRect( density, policoord ).x / 20.0;
	intensity = clamp( intensity, 0.0, 1.0 );
	gl_Position = ftransform();
}
