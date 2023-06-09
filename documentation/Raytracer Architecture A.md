- Color
	- variable mutex private
	- operator [](const Enum &type)
		- thread safe
	- toute les opérations
		- thread safe

- SceneLoader
	- constructor (const string &filePath)
	- subscribe("onChange", callback(configuration))
	- update()

- EntityFactory
	- register(const string &name, unique_ptr<PluginHandler>)
	- get(const string &name, IConfig) : IEntity
	- static getInstance() : EntityFactory

	- static private variable d'un unique_ptr de EntityFactory

- Enum EntityType
	- Light
	- Camera
	- Primitive

- PluginHandler
	- getType : Enum EntityType
	- getEntity(IConfig) : IEntity

- IEntityCreator
	- create(IConfig) : std::unique_ptr<IEntity>

- extern C
	- IEntityCreator *getEntityCreator(void);
	- void deleteEntityCreator(IEntityCreator *creator);

- PluginLoader
	- constructor (const string &directory)
	- load()

*la function renders de scene est appelé lui même dans un autre thread et pas dans le thread principal pour qu'on puisse stopper l'action de rendering*
- Scene
	- operator()
	- renders() [check si la function isReady renvoie false]
	- const &list<const Image &> getImages() const
	- isReady() : bool

	private:
	- list<std::unique_ptr<ICamera>>
	- variable displayable
	- variable mutex
	- variable thread

- Displayable
	- const list<std::unique_ptr<ILight>> &getLightList() const
	- const list<std::unique_ptr<IPrimitive>> &getPrimitiveList() const
	- list<std::unique_ptr<ILight>> &getLightList()
	- list<std::unique_ptr<IPrimitive>> &getPrimitiveList()

	private:
	- list<std::unique_ptr<ILight>>
	- list<std::unique_ptr<IPrimitive>>


- ICamera !!
	- render(const Displayable &displayable) : const &Image
	- const &Image getImage() const

	- list<std::unique_ptr<IFilter>>
	- variable Image

- IFilter
	- apply(Image &image)

- FilterHandler
	- getFilter(IConfig) : IFilter

- IFilterCreator
	- create(IConfig) : std::unique_ptr<IFilter>

- extern C
	- IFilterCreator *getFilterCreator(void);
	- void deleteFilterCreator(IFilterCreator *creator);

- FilterLoader
	- constructor (const string &directory)
	- load()

- FilterFactory
	- register(const string &name, unique_ptr<FilterHandler>)
	- get(const string &name, IConfig) : IFilter
	- static getInstance() : FilterFactory

	- static private variable d'un unique_ptr de FilterFactory


- PixelThread
	- constructor(const Displayable &displayable, Color &color)
	- operator()

- ImagePipeLine
	- constructor (Image &image, const Displayable &displayable)
	- generate(maxThread = .., int cluster = 1)
	- apply(Filter)

- Image
	- constructor (const Vector2i &size)
	- convertToPPM
	- convertToSfTexture
	- operator[] : PixelLine

	- list<Pixel>

- PixelLine
	- constructor (list<Pixel> &list, int y)
	- operator[] : &Color
