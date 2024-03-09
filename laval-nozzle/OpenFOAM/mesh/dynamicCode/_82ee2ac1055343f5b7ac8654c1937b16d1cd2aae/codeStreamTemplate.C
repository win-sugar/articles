/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with codeStream.

\*---------------------------------------------------------------------------*/

#include "dictionary.H"
#include "Ostream.H"
#include "Pstream.H"
#include "pointField.H"
#include "tensor.H"
#include "unitConversion.H"

//{{{ begin codeInclude
#line 55 "/mnt/c/Users/sato/OneDrive/Desktop/vbox/github-pages/laval-nozzle/OpenFOAM/mesh/system/blockMeshDict/#codeStream"
#include "pointField.H"
        #include "mathematicalConstants.H"
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C" void codeStream_82ee2ac1055343f5b7ac8654c1937b16d1cd2aae(Foam::Ostream& os, const Foam::dictionary& dict)
{
//{{{ begin code
    #line 61 "/mnt/c/Users/sato/OneDrive/Desktop/vbox/github-pages/laval-nozzle/OpenFOAM/mesh/system/blockMeshDict/#codeStream"
constexpr scalar xMin = 0;
        constexpr scalar xMax = 10;
        constexpr label nPoints = 200 + 1;
        constexpr scalar dx = (xMax - xMin)/scalar(nPoints - 1);
        constexpr scalar pi = constant::mathematical::pi;

        scalar cs = cos(2.5*pi/180.0);
        scalar sn = sin(2.5*pi/180.0);

        os  << "(" << nl << "spline 2 3" << nl;
        pointField profile(nPoints);

        for (label i = 0; i < nPoints; ++i)
        {
            scalar x = xMin + i*dx;
            scalar r(0.0);
            if ( x < 5.0 ) {
              scalar area ( 1.75 - 0.75 * cos( ( 0.2 * x - 1.0 ) * pi ) );
              r = sqrt(area/pi);
            }
            else {
              scalar area ( 1.25 - 0.25 * cos( ( 0.2 * x - 1.0 ) * pi ) );
              r = sqrt(area/pi);
            }
            profile[i].x() = x;
            profile[i].y() = r*cs;
            profile[i].z() =-r*sn;
        }
        os << profile << nl;

        os << "spline 4 5" << nl;
        for (label i = 0; i < nPoints; ++i)
        {
            scalar x = xMin + i*dx;
            scalar r(0.0);
            if ( x < 5.0 ) {
              scalar area ( 1.75 - 0.75 * cos( ( 0.2 * x - 1.0 ) * pi ) );
              r = sqrt(area/pi);
            }
            else {
              scalar area ( 1.25 - 0.25 * cos( ( 0.2 * x - 1.0 ) * pi ) );
              r = sqrt(area/pi);
            }
            profile[i].x() = x;
            profile[i].y() = r*cs;
            profile[i].z() = r*sn;
        }
        os << profile << nl;

        os  << ");" << nl;
//}}} end code
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

