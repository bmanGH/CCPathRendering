//
//  CCPathRenderingTestScene.h
//  CCPathRenderingDemo
//
//  Created by bman on 3/9/14.
//
//

#ifndef __CCPathRenderingDemo__CCPathRenderingTestScene__
#define __CCPathRenderingDemo__CCPathRenderingTestScene__

#include "cocos2d.h"
#include "cocos-ext.h"

//#include "MonkVG/openvg.h"
//#include "MonkVG/vgu.h"
//#include "MonkVG/vgext.h"

#include "CCPathRendering/CCGraphicsNode.h"
#include "CCPathRendering/CCPathRenderingPaint.h"
#include "CCPathRendering/CCPathRenderingPath.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCPathRenderingTestScene : public Layer
{
private:
    CustomCommand _customRenderCommand;
    
//    VGPath	_path;
//	VGPaint _paint;
//	VGPaint _linearGradientPaint;
//	VGPaint _radialGradientPaint;
//    //	VGImage _image;
//    //	VGImage	_bitmapFont;
//	//	VGImage _gradientImage;
//	VGPath _linearGradientPath;
//	VGPath _radialGradientPath;
//	VGFont	_font;
//	VGfloat _lineHeight;
    
    GraphicsNode* _graphicsNode;
    
public:
    static Scene* scene();
    CREATE_FUNC(CCPathRenderingTestScene);
    
    virtual ~CCPathRenderingTestScene ();
    
    virtual bool init();
    
    // update
    virtual void update (float delta) override;
    
    // draw
    virtual void draw (Renderer* renderer, const kmMat4 &transform, bool transformUpdated) override;
    void render ();
    
    // touch callback
    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *event) override;
    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *event) override;
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *event) override;
    virtual void onTouchesCancelled(const std::vector<Touch*>& touches, Event *event) override;
};

#endif /* defined(__CCPathRenderingDemo__CCPathRenderingTestScene__) */
