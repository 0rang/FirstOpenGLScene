## Next Action: 
#
# Mark Bands
## 40-50
- [X] A "complex" object/scene made of multiple convex objects
- [X] Lighting, recognisable:
  - [X] diffusive
  - [X] specular

## 50-60
- [X] User Interaction (one element) 

## 60-70
- [X] Animation i.e rotating objects
- [ ] Texture mapping (Eyes: Marc, Markus, Globe: Spider butt)
   (Marc says just setting the u,v is fine, although you might get creativity points for using the wrapping modes)
- [X] Convex object constructed from polygons 

## 70-100
- [ ] Hierarchichal modelling (push & pop matrix)
  - [ ] Partial motion within the object
  - [ ] Object itself should move in a circle through the scene
- [ ] Various UI elements, e.g:
  - [ ] Controls to set radius or speed of the object
  - [ ] Dialogue boxes to control material properties
  - [ ] Toggle textures (my idea)
  - [ ] Button to pause all the animation (use an && to make this work alongside individual, hardcoded pausing)



## Vincent's textures advice
Before you use textures, you need to:

Load in the image file - if you're using Qt, you can use an QImage to load in the file. Just make sure the path you specify is correct.
	
Send the image data (bytes) to OpenGL - you would need to generate a free texture id, bind it to the currently active texture unit, then send the 2D image to OpenGL. These 3 things correspond to glGenTextures, glBindTexture, and glTexImage2D. If you used an QImage, then you can get the image data out easily with a method, but it might not conform to OpenGL's format. But don't worry, there's a convenient static method in QGLWidget that lets you change the format.
	
Once the texture is loaded into the GPU, you can set various texture parameters with glTexParameters. Consult the doc at that point.

If you have multiple texture units, you can set the active one by calling glBindTexture with the appropriate id. 
To apply textures onto faces (e.g. squares), you need to give each vertex some texture coordinates, i.e. call glTexCoord2f before you do glVertex3f. 


# My own ideas (ALL DEAD)
- [ ] Mech animation where all of its glut components do some elastic movement in a randomly generated direction vector. then returns to normal
- [ ] Convex polygonal object can be a spinning top tetrahedron 
- [ ] http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/ << if you want to load some models
## Fluid project ideas
- [ ] 3D arrow that takes some vector and changes direction and colour based on the vector, but does not get longer than some clamp value

## Dead ideas

