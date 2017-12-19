let project = new Project('krafix', __dirname);

project.setCmd();

project.cpp11 = true;

project.addExclude('.git/**');
project.addExclude('build/**');

project.addFile('Sources/**');

resolve(project);
