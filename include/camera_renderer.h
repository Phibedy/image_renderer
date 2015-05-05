#ifndef CAMERA_RENDERER_H
#define CAMERA_RENDERER_H

#include <ogre/visualmanager.h>
#include <lms/datamanager.h>
#include <lms/module.h>
#include <ogre/window.h>
#include <lms/imaging/image.h>

#include <OGRE/OgreBillboardSet.h>
#include <OGRE/OgreMaterial.h>
#include <OGRE/OgreTexture.h>
#include <OGRE/OgreRectangle2D.h>

class Camera_plain : public lms::Module {
public:
	bool initialize();
	bool deinitialize();

	bool cycle();

protected: 
    visual::Window *window;
    float plane_size;
    int texture_size;
    /**
     * @brief image the image to draw
     */
    const lms::imaging::Image* image;

    Ogre::MaterialPtr imageGroundMaterial;
    /**
     * @brief imageTexture texture that will be drawn on the billboard
     */
    Ogre::TexturePtr imageTexture;
    
    Ogre::SceneNode *rootNode;
    /**
     * @brief rect image will be drawn inside the rect
     */
    Ogre::Rectangle2D* rect;
private:
    int lastWidth;
    int lastHeight;

    /**
     * name that written before the modulename to get the material
     *
     */
    std::string groundMatName;

    void setupEnvironment(int width, int height);
    void drawImage();
};

#endif /* CAMERA_RENDERER_H */
