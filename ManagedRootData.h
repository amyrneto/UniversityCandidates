public ref class ManagedRootData
{
public:
    RootData* nativeRootData;

    ManagedRootData(const RootData& data)
    {
        nativeRootData = new RootData(data);
    }

    ~ManagedRootData()
    {
        delete nativeRootData;
    }
};
