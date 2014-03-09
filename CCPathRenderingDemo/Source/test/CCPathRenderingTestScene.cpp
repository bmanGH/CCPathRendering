//
//  CCPathRenderingTestScene.cpp
//  CCPathRenderingDemo
//
//  Created by bman on 3/9/14.
//
//

#include "CCPathRenderingTestScene.h"

Scene* CCPathRenderingTestScene::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    CCPathRenderingTestScene *layer = CCPathRenderingTestScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

CCPathRenderingTestScene::~CCPathRenderingTestScene ()
{
}

bool CCPathRenderingTestScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
// MonkVG test
//    vgCreateContextMNK( 1136, 640, VG_RENDERING_BACKEND_TYPE_OPENGLES20 );
//
//    // create a paint
//    _paint = vgCreatePaint();
//    vgSetPaint(_paint, VG_FILL_PATH );
//
//    VGfloat color[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
//    vgSetParameterfv(_paint, VG_PAINT_COLOR, 4, &color[0]);
//
//    _path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,1,0,0,0, VG_PATH_CAPABILITY_ALL);
//    vguRect( _path, 50.0f, 50.0f, 90.0f, 50.0f );
//
//    vgSetf( VG_STROKE_LINE_WIDTH, 7.0f );
//
//    _lineHeight = 74;	// hardwired.  todo: read from file
//
//    // create a path for linear gradient
//    _linearGradientPath = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,1,0,0,0, VG_PATH_CAPABILITY_ALL);
//    vguRect( _linearGradientPath, 0, 0, 120.0f, 40.0f );
//
//    // create a linear gradient paint to apply to the path
//    _linearGradientPaint = vgCreatePaint();
//    vgSetParameteri(_linearGradientPaint, VG_PAINT_TYPE, VG_PAINT_TYPE_LINEAR_GRADIENT);
//
//    // A linear gradient needs start and end points that describe orientation
//    // and length of the gradient.
//    float afLinearGradientPoints[4] = {
//        0.0f, 0.0f,
//        120.0f, 0.0f
//    };
//    vgSetParameterfv(_linearGradientPaint, VG_PAINT_LINEAR_GRADIENT, 4, afLinearGradientPoints);
//
//    // Now we have to specify the colour ramp. It is described by "stops" that
//    // are given as premultiplied sRGBA colour at a position between 0 and 1.
//    // Between these stops, the colour is linearly interpolated.
//    // This colour ramp goes from red to green to blue, all opaque.
//    float stops[3][5] = {
//        {0.0f,	1.0f, 0.0f, 0.0f, 1.0f},
//        {0.5f,	0.0f, 1.0f, 0.0f, 0.8f},
//        {1.0f,	0.0f, 0.0f, 1.0f, 0.4f}
//    };
//    vgSetParameterfv(_linearGradientPaint, VG_PAINT_COLOR_RAMP_STOPS, 15, &stops[0][0]);
//
//    // setup radial gradient
//    _radialGradientPath = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,1,0,0,0, VG_PATH_CAPABILITY_ALL);
//    vguEllipse( _radialGradientPath, 0, 0, 90.0f, 50.0f );
//
//    _radialGradientPaint = vgCreatePaint();
//    vgSetParameteri(_radialGradientPaint, VG_PAINT_TYPE, VG_PAINT_TYPE_RADIAL_GRADIENT);
//    float afRadialGradient[5] = {45,25,45,25,45.0f };	// { cx, cy, fx, fy, r }.
//    vgSetParameterfv(_radialGradientPaint, VG_PAINT_RADIAL_GRADIENT, 5, afRadialGradient);
//    vgSetParameterfv(_radialGradientPaint, VG_PAINT_COLOR_RAMP_STOPS, 15, &stops[0][0]);
    
    // CCPathRendering test
    PathRenderingPaint* paint = new PathRenderingPaint(PathRenderingPaint::PAINT_TYPE_RADIAL_GRADIENT);
    float afRadialGradient[5] = { 45,25,45,25,45.0f };
    paint->setRadialGradient(afRadialGradient);
    float stops[3][5] = {
        {0.0f,	1.0f, 0.0f, 0.0f, 1.0f},
        {0.5f,	0.0f, 1.0f, 0.0f, 0.8f},
        {1.0f,	0.0f, 0.0f, 1.0f, 0.4f}
    };
    paint->setColorRampStops(&stops[0][0], 15);
    
    PathRenderingPath* path = new PathRenderingPath();
    path->ellipse(Point(0, 0), Size(90, 50));
    path->fill(paint, PathRenderingPath::FILL_RULE_EVEN_ODD);
    
    _graphicsNode = GraphicsNode::create();
    _graphicsNode->addPath(path);
    _graphicsNode->setPosition(150, 150);
    this->addChild(_graphicsNode);
    
    path->release();
    paint->release();
    
    
    paint = new PathRenderingPaint(PathRenderingPaint::PAINT_TYPE_LINEAR_GRADIENT);
    float afLinearGradientPoints[4] = {
        0.0f, 0.0f,
        120.0f, 0.0f
    };
    paint->setLinearGradient(afLinearGradientPoints);
    paint->setColorRampStops(&stops[0][0], 15);
    
    PathRenderingPaint* paint2 = new PathRenderingPaint(PathRenderingPaint::PAINT_TYPE_COLOR);
    paint2->setPaintColor(Color4F::BLUE);
    
    path = new PathRenderingPath();
    path->rect(Point(0, 0), Size(120.0f, 40.0f));
    path->fillAndStroke(paint, PathRenderingPath::FILL_RULE_NON_ZERO, paint2, 4);
    
    //    _graphicsNode = GraphicsNode::create();
    _graphicsNode->addPath(path);
    //    _graphicsNode->setPosition(350, 350);
    //    this->addChild(_graphicsNode);
    
    path->release();
    paint->release();
    
    
    paint = new PathRenderingPaint(PathRenderingPaint::PAINT_TYPE_COLOR);
    paint->setPaintColor(Color4F::RED);
    
    path = new PathRenderingPath();
    path->triangle(Point(50, 50), Point(150, 50), Point(100, 125));
    path->stroke(paint, 7);
    
    //    _graphicsNode = GraphicsNode::create();
    _graphicsNode->addPath(path);
    //    _graphicsNode->setPosition(500, 350);
    //    this->addChild(_graphicsNode);
    
    path->release();
    paint->release();
    
    return true;
}


#pragma mark - Update

void CCPathRenderingTestScene::update (float delta) {
    
}


#pragma mark - Draw

void CCPathRenderingTestScene::draw (Renderer* renderer, const kmMat4 &transform, bool transformUpdated) {
    _customRenderCommand.init(_globalZOrder);
    _customRenderCommand.func = CC_CALLBACK_0(CCPathRenderingTestScene::render, this);
    Director::getInstance()->getRenderer()->addCommand(&_customRenderCommand);
}

void CCPathRenderingTestScene::render () {
//    // get the width and height of the screen
//    VGint backingWidth = vgGeti( VG_SURFACE_WIDTH_MNK );
//    VGint backingHeight = vgGeti( VG_SURFACE_HEIGHT_MNK );
//
////    CCLOG("backingWidth:%i backingHeight:%i", backingWidth, backingHeight);
//
////    VGfloat clearColor[] = {1,1,1,1};
////	vgSetfv(VG_CLEAR_COLOR, 4, clearColor);
////	vgClear(0,0,backingWidth,backingHeight);
//
//	/// draw the basic path
////	vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
////	vgLoadIdentity();
////	vgTranslate( backingWidth/2, backingHeight/2 );
//	vgSetPaint( _paint, VG_STROKE_PATH );
//	vgDrawPath( _path, VG_STROKE_PATH );
//
//	// draw the gradient path
////	vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
////	vgLoadIdentity();
////	vgTranslate( backingWidth/2, backingHeight/2 );
//	vgSetPaint( _linearGradientPaint, VG_FILL_PATH );
//	vgDrawPath( _linearGradientPath, VG_FILL_PATH );
//
//	// draw radial gradient
////	vgLoadIdentity();
////	vgTranslate( 50, backingHeight/2 + 20 );
//	vgSetPaint( _radialGradientPaint, VG_FILL_PATH );
//	vgDrawPath( _radialGradientPath, VG_FILL_PATH );
}


#pragma mark - Touch callback

void CCPathRenderingTestScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *event) {
    
}

void CCPathRenderingTestScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *event) {
    
}

void CCPathRenderingTestScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *event) {
    
}

void CCPathRenderingTestScene::onTouchesCancelled(const std::vector<Touch*>& touches, Event *event) {
    
}
