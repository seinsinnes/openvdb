///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2012-2013 DreamWorks Animation LLC
//
// All rights reserved. This software is distributed under the
// Mozilla Public License 2.0 ( http://www.mozilla.org/MPL/2.0/ )
//
// Redistributions of source code must retain the above copyright
// and license notice and the following restrictions and disclaimer.
//
// *     Neither the name of DreamWorks Animation nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// IN NO EVENT SHALL THE COPYRIGHT HOLDERS' AND CONTRIBUTORS' AGGREGATE
// LIABILITY FOR ALL CLAIMS REGARDLESS OF THEIR BASIS EXCEED US$250.00.
//
///////////////////////////////////////////////////////////////////////////


#include <openvdb/Types.h> // for OPENVDB_START_THREADSAFE_STATIC_WRITE
#include <GLFW/glfw3.h>
#include "Font.h"

namespace openvdb_viewer {

GLuint BitmapFont13::sOffset = 0;

GLubyte BitmapFont13::sCharacters[95][13] = {
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X18, 0X18, 0X00, 0X00, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18 },
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X36, 0X36, 0X36, 0X36 },
    { 0X00, 0X00, 0X00, 0X66, 0X66, 0XFF, 0X66, 0X66, 0XFF, 0X66, 0X66, 0X00, 0X00 },
    { 0X00, 0X00, 0X18, 0X7E, 0XFF, 0X1B, 0X1F, 0X7E, 0XF8, 0XD8, 0XFF, 0X7E, 0X18 },
    { 0X00, 0X00, 0X0E, 0X1B, 0XDB, 0X6E, 0X30, 0X18, 0X0C, 0X76, 0XDB, 0XD8, 0X70 },
    { 0X00, 0X00, 0X7F, 0XC6, 0XCF, 0XD8, 0X70, 0X70, 0XD8, 0XCC, 0XCC, 0X6C, 0X38 },
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X18, 0X1C, 0X0C, 0X0E },
    { 0X00, 0X00, 0X0C, 0X18, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X18, 0X0C },
    { 0X00, 0X00, 0X30, 0X18, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X18, 0X30 },
    { 0X00, 0X00, 0X00, 0X00, 0X99, 0X5A, 0X3C, 0XFF, 0X3C, 0X5A, 0X99, 0X00, 0X00 },
    { 0X00, 0X00, 0X00, 0X18, 0X18, 0X18, 0XFF, 0XFF, 0X18, 0X18, 0X18, 0X00, 0X00 },
    { 0X00, 0X00, 0X30, 0X18, 0X1C, 0X1C, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0XFF, 0XFF, 0X00, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X00, 0X38, 0X38, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X60, 0X60, 0X30, 0X30, 0X18, 0X18, 0X0C, 0X0C, 0X06, 0X06, 0X03, 0X03 },
    { 0X00, 0X00, 0X3C, 0X66, 0XC3, 0XE3, 0XF3, 0XDB, 0XCF, 0XC7, 0XC3, 0X66, 0X3C },
    { 0X00, 0X00, 0X7E, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X78, 0X38, 0X18 },
    { 0X00, 0X00, 0XFF, 0XC0, 0XC0, 0X60, 0X30, 0X18, 0X0C, 0X06, 0X03, 0XE7, 0X7E },
    { 0X00, 0X00, 0X7E, 0XE7, 0X03, 0X03, 0X07, 0X7E, 0X07, 0X03, 0X03, 0XE7, 0X7E },
    { 0X00, 0X00, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0XFF, 0XCC, 0X6C, 0X3C, 0X1C, 0X0C },
    { 0X00, 0X00, 0X7E, 0XE7, 0X03, 0X03, 0X07, 0XFE, 0XC0, 0XC0, 0XC0, 0XC0, 0XFF },
    { 0X00, 0X00, 0X7E, 0XE7, 0XC3, 0XC3, 0XC7, 0XFE, 0XC0, 0XC0, 0XC0, 0XE7, 0X7E },
    { 0X00, 0X00, 0X30, 0X30, 0X30, 0X30, 0X18, 0X0C, 0X06, 0X03, 0X03, 0X03, 0XFF },
    { 0X00, 0X00, 0X7E, 0XE7, 0XC3, 0XC3, 0XE7, 0X7E, 0XE7, 0XC3, 0XC3, 0XE7, 0X7E },
    { 0X00, 0X00, 0X7E, 0XE7, 0X03, 0X03, 0X03, 0X7F, 0XE7, 0XC3, 0XC3, 0XE7, 0X7E },
    { 0X00, 0X00, 0X00, 0X38, 0X38, 0X00, 0X00, 0X38, 0X38, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X30, 0X18, 0X1C, 0X1C, 0X00, 0X00, 0X1C, 0X1C, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X06, 0X0C, 0X18, 0X30, 0X60, 0XC0, 0X60, 0X30, 0X18, 0X0C, 0X06 },
    { 0X00, 0X00, 0X00, 0X00, 0XFF, 0XFF, 0X00, 0XFF, 0XFF, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X60, 0X30, 0X18, 0X0C, 0X06, 0X03, 0X06, 0X0C, 0X18, 0X30, 0X60 },
    { 0X00, 0X00, 0X18, 0X00, 0X00, 0X18, 0X18, 0X0C, 0X06, 0X03, 0XC3, 0XC3, 0X7E },
    { 0X00, 0X00, 0X3F, 0X60, 0XCF, 0XDB, 0XD3, 0XDD, 0XC3, 0X7E, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XC3, 0XC3, 0XC3, 0XC3, 0XFF, 0XC3, 0XC3, 0XC3, 0X66, 0X3C, 0X18 },
    { 0X00, 0X00, 0XFE, 0XC7, 0XC3, 0XC3, 0XC7, 0XFE, 0XC7, 0XC3, 0XC3, 0XC7, 0XFE },
    { 0X00, 0X00, 0X7E, 0XE7, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XE7, 0X7E },
    { 0X00, 0X00, 0XFC, 0XCE, 0XC7, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC7, 0XCE, 0XFC },
    { 0X00, 0X00, 0XFF, 0XC0, 0XC0, 0XC0, 0XC0, 0XFC, 0XC0, 0XC0, 0XC0, 0XC0, 0XFF },
    { 0X00, 0X00, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XFC, 0XC0, 0XC0, 0XC0, 0XFF },
    { 0X00, 0X00, 0X7E, 0XE7, 0XC3, 0XC3, 0XCF, 0XC0, 0XC0, 0XC0, 0XC0, 0XE7, 0X7E },
    { 0X00, 0X00, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XFF, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3 },
    { 0X00, 0X00, 0X7E, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X7E },
    { 0X00, 0X00, 0X7C, 0XEE, 0XC6, 0X06, 0X06, 0X06, 0X06, 0X06, 0X06, 0X06, 0X06 },
    { 0X00, 0X00, 0XC3, 0XC6, 0XCC, 0XD8, 0XF0, 0XE0, 0XF0, 0XD8, 0XCC, 0XC6, 0XC3 },
    { 0X00, 0X00, 0XFF, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0 },
    { 0X00, 0X00, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XDB, 0XFF, 0XFF, 0XE7, 0XC3 },
    { 0X00, 0X00, 0XC7, 0XC7, 0XCF, 0XCF, 0XDF, 0XDB, 0XFB, 0XF3, 0XF3, 0XE3, 0XE3 },
    { 0X00, 0X00, 0X7E, 0XE7, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XE7, 0X7E },
    { 0X00, 0X00, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XFE, 0XC7, 0XC3, 0XC3, 0XC7, 0XFE },
    { 0X00, 0X00, 0X3F, 0X6E, 0XDF, 0XDB, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0X66, 0X3C },
    { 0X00, 0X00, 0XC3, 0XC6, 0XCC, 0XD8, 0XF0, 0XFE, 0XC7, 0XC3, 0XC3, 0XC7, 0XFE },
    { 0X00, 0X00, 0X7E, 0XE7, 0X03, 0X03, 0X07, 0X7E, 0XE0, 0XC0, 0XC0, 0XE7, 0X7E },
    { 0X00, 0X00, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0XFF },
    { 0X00, 0X00, 0X7E, 0XE7, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3 },
    { 0X00, 0X00, 0X18, 0X3C, 0X3C, 0X66, 0X66, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3 },
    { 0X00, 0X00, 0XC3, 0XE7, 0XFF, 0XFF, 0XDB, 0XDB, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3 },
    { 0X00, 0X00, 0XC3, 0X66, 0X66, 0X3C, 0X3C, 0X18, 0X3C, 0X3C, 0X66, 0X66, 0XC3 },
    { 0X00, 0X00, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X3C, 0X3C, 0X66, 0X66, 0XC3 },
    { 0X00, 0X00, 0XFF, 0XC0, 0XC0, 0X60, 0X30, 0X7E, 0X0C, 0X06, 0X03, 0X03, 0XFF },
    { 0X00, 0X00, 0X3C, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X3C },
    { 0X00, 0X03, 0X03, 0X06, 0X06, 0X0C, 0X0C, 0X18, 0X18, 0X30, 0X30, 0X60, 0X60 },
    { 0X00, 0X00, 0X3C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X3C },
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0XC3, 0X66, 0X3C, 0X18 },
    { 0XFF, 0XFF, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X18, 0X38, 0X30, 0X70 },
    { 0X00, 0X00, 0X7F, 0XC3, 0XC3, 0X7F, 0X03, 0XC3, 0X7E, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XFE, 0XC3, 0XC3, 0XC3, 0XC3, 0XFE, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0 },
    { 0X00, 0X00, 0X7E, 0XC3, 0XC0, 0XC0, 0XC0, 0XC3, 0X7E, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X7F, 0XC3, 0XC3, 0XC3, 0XC3, 0X7F, 0X03, 0X03, 0X03, 0X03, 0X03 },
    { 0X00, 0X00, 0X7F, 0XC0, 0XC0, 0XFE, 0XC3, 0XC3, 0X7E, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X30, 0X30, 0X30, 0X30, 0X30, 0XFC, 0X30, 0X30, 0X30, 0X33, 0X1E },
    { 0X7E, 0XC3, 0X03, 0X03, 0X7F, 0XC3, 0XC3, 0XC3, 0X7E, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XC3, 0XFE, 0XC0, 0XC0, 0XC0, 0XC0 },
    { 0X00, 0X00, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X00, 0X00, 0X18, 0X00 },
    { 0X38, 0X6C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X0C, 0X00, 0X00, 0X0C, 0X00 },
    { 0X00, 0X00, 0XC6, 0XCC, 0XF8, 0XF0, 0XD8, 0XCC, 0XC6, 0XC0, 0XC0, 0XC0, 0XC0 },
    { 0X00, 0X00, 0X7E, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X78 },
    { 0X00, 0X00, 0XDB, 0XDB, 0XDB, 0XDB, 0XDB, 0XDB, 0XFE, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XC6, 0XC6, 0XC6, 0XC6, 0XC6, 0XC6, 0XFC, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X7C, 0XC6, 0XC6, 0XC6, 0XC6, 0XC6, 0X7C, 0X00, 0X00, 0X00, 0X00 },
    { 0XC0, 0XC0, 0XC0, 0XFE, 0XC3, 0XC3, 0XC3, 0XC3, 0XFE, 0X00, 0X00, 0X00, 0X00 },
    { 0X03, 0X03, 0X03, 0X7F, 0XC3, 0XC3, 0XC3, 0XC3, 0X7F, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XC0, 0XC0, 0XC0, 0XC0, 0XC0, 0XE0, 0XFE, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XFE, 0X03, 0X03, 0X7E, 0XC0, 0XC0, 0X7F, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X1C, 0X36, 0X30, 0X30, 0X30, 0X30, 0XFC, 0X30, 0X30, 0X30, 0X00 },
    { 0X00, 0X00, 0X7E, 0XC6, 0XC6, 0XC6, 0XC6, 0XC6, 0XC6, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X18, 0X3C, 0X3C, 0X66, 0X66, 0XC3, 0XC3, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XC3, 0XE7, 0XFF, 0XDB, 0XC3, 0XC3, 0XC3, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XC3, 0X66, 0X3C, 0X18, 0X3C, 0X66, 0XC3, 0X00, 0X00, 0X00, 0X00 },
    { 0XC0, 0X60, 0X60, 0X30, 0X18, 0X3C, 0X66, 0X66, 0XC3, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0XFF, 0X60, 0X30, 0X18, 0X0C, 0X06, 0XFF, 0X00, 0X00, 0X00, 0X00 },
    { 0X00, 0X00, 0X0F, 0X18, 0X18, 0X18, 0X38, 0XF0, 0X38, 0X18, 0X18, 0X18, 0X0F },
    { 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18 },
    { 0X00, 0X00, 0XF0, 0X18, 0X18, 0X18, 0X1C, 0X0F, 0X1C, 0X18, 0X18, 0X18, 0XF0 },
    { 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X06, 0X8F, 0XF1, 0X60, 0X00, 0X00, 0X00 }
}; // sCharacters


void
BitmapFont13::initialize()
{
    OPENVDB_START_THREADSAFE_STATIC_WRITE

    glShadeModel(GL_FLAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    BitmapFont13::sOffset = glGenLists(128);

    for (GLuint c = 32; c < 127; ++c) {
        glNewList(c + BitmapFont13::sOffset, GL_COMPILE);
        glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, BitmapFont13::sCharacters[c-32]);
        glEndList();
    }
    OPENVDB_FINISH_THREADSAFE_STATIC_WRITE
}


void
BitmapFont13::enableFontRendering(GLFWwindow *wnd)
{
    glPushMatrix();
    int width, height;
    glfwGetWindowSize(wnd, &width, &height);
    height = height < 1 ? 1 : height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho (0, width, 0, height, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glShadeModel(GL_FLAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}


void
BitmapFont13::disableFontRendering()
{
    glFlush();
    glPopMatrix();
}


void
BitmapFont13::print(GLint px, GLint py, const std::string& str)
{
    glRasterPos2i(px, py);
    glPushAttrib(GL_LIST_BIT);
    glListBase(BitmapFont13::sOffset);
    glCallLists(str.length(), GL_UNSIGNED_BYTE, reinterpret_cast<const GLubyte*>(str.c_str()));
    glPopAttrib();
}

} // namespace openvdb_viewer

// Copyright (c) 2012-2013 DreamWorks Animation LLC
// All rights reserved. This software is distributed under the
// Mozilla Public License 2.0 ( http://www.mozilla.org/MPL/2.0/ )
