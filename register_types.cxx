
#include "register_types.h"
#include "object_type_db.h"
#include "reference.h"

// Wrap for oda
#include "engine.h"

#include <vector>
#include <string>

using std::string;
using std::vector;

const static string paths[1] = {"patches"};

class ODAModule : public Reference {
  OBJ_TYPE(ODAModule, Reference);
  public:
    ODAModule ()
      : engine_(vector<string>(paths, paths + sizeof(paths)/sizeof(string))) {}
    bool ok () const { return engine_.ok(); }
  protected:
    static void _bind_methods () {
      ObjectTypeDB::bind_method("ok", &ODAModule::ok);
    }
  private:
    oda::godot::Engine engine_;
};

void register_openda_types () {
  ObjectTypeDB::register_type<ODAModule>();
}

void unregister_openda_types () {
  // nothing at all?
}

