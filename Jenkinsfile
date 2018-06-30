pipeline {
  agent {
    dockerfile true 
  }
  stages {
    stage('configure') {
      steps {
        echo 'Configuring..'
        sh 'mkdir build && cd build && cmake -DBUILD_TESTING=on .. '
      }
    }
    stage('build') {
      steps {
        echo 'Building..'
        sh 'cd build && cmake --build .'
      }
    }
    stage('test') {
      steps {
        echo 'Testing..'
        sh 'cd build && ctest'
      }
    }
  }
  post { 
        success { 
            echo 'pipeline success :) !'
        }
        failure { 
            echo 'pipeline failure :( !'
        }
    }
}
