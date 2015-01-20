/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "renderer/CCBatch.h"
#include "renderer/CCVertexIndexBuffer.h"

NS_CC_BEGIN

const VertexData* Batch::getVertexData() const
{
    return _verts;
}

const IndexBuffer* Batch::getIndexData() const
{
    return _indices;
}

Batch::Batch()
: _verts(nullptr)
, _indices(nullptr)
, _drawingPrimitive(-1)
{
}

Batch::~Batch()
{
    CC_SAFE_RELEASE_NULL(_verts);
    CC_SAFE_RELEASE_NULL(_indices);
}

bool Batch::init(VertexData* verts, IndexBuffer* indices, int drawingPrimitive)
{
    if (nullptr == verts)
        return false;
    
    if (verts != _verts)
    {
        CC_SAFE_RELEASE(_verts);
        CC_SAFE_RETAIN(verts);
        _verts = verts;
    }
    
    if (indices != _indices)
    {
        CC_SAFE_RETAIN(indices);
        CC_SAFE_RELEASE(_indices);
        _indices = indices;
    }
    
    _drawingPrimitive = drawingPrimitive;
    
    return true;
}

void Batch::draw()
{
    if(_verts)
        _verts->draw();
}

NS_CC_END
