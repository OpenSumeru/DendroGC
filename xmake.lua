

target("DendroGC")
    set_kind("shared")
    add_includedirs("include")
    add_files("src/*.cpp")
target_end()

target("main")
    set_kind("binary")
    add_includedirs("include")
    --set_pcxxheader("include/*.hpp")
    add_files("*.cpp")
    add_deps("DendroGC")
target_end()
    