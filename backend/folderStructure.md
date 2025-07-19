ProcessMonitor/
├── CMakeLists.txt                          # Main CMake configuration
├── README.md
├── LICENSE
├── .gitignore
├── config.json                            # Drogon configuration
├── docker-compose.yml
├── build.sh                               # Build script
├── run.sh                                 # Run script
├── backend/                               # C++ Backend with Drogon
│   ├── CMakeLists.txt                     # Backend CMake
│   ├── main.cpp                           # Application entry point
│   ├── config/                            # Configuration files
│   │   ├── config.json                    # Drogon server config
│   │   ├── db_config.json                 # Database config (if needed)
│   │   └── app_config.json                # Application specific config
│   ├── controllers/                       # Drogon Controllers
│   │   ├── ProcessController.h
│   │   ├── ProcessController.cpp
│   │   ├── SystemController.h
│   │   ├── SystemController.cpp
│   │   ├── ConfigController.h
│   │   ├── ConfigController.cpp
│   │   ├── LogController.h
│   │   ├── LogController.cpp
│   │   ├── WebSocketController.h
│   │   └── WebSocketController.cpp
│   ├── models/                            # Data Models
│   │   ├── ProcessConfig.h
│   │   ├── ProcessConfig.cpp
│   │   ├── ProcessInfo.h
│   │   ├── ProcessInfo.cpp
│   │   ├── ProcessStatus.h
│   │   ├── ProcessStatus.cpp
│   │   ├── SystemInfo.h
│   │   ├── SystemInfo.cpp
│   │   ├── ApiResponse.h
│   │   └── ApiResponse.cpp
│   ├── services/                          # Business Logic Services
│   │   ├── ProcessMonitorService.h
│   │   ├── ProcessMonitorService.cpp
│   │   ├── ProcessManagerService.h
│   │   ├── ProcessManagerService.cpp
│   │   ├── HealthCheckService.h
│   │   ├── HealthCheckService.cpp
│   │   ├── RestartStrategyService.h
│   │   ├── RestartStrategyService.cpp
│   │   ├── ConfigurationService.h
│   │   ├── ConfigurationService.cpp
│   │   ├── LoggingService.h
│   │   ├── LoggingService.cpp
│   │   ├── NotificationService.h
│   │   └── NotificationService.cpp
│   ├── core/                              # Core Engine
│   │   ├── ProcessMonitor.h
│   │   ├── ProcessMonitor.cpp
│   │   ├── MonitoredProcess.h
│   │   ├── MonitoredProcess.cpp
│   │   ├── HealthChecker.h
│   │   ├── HealthChecker.cpp
│   │   ├── RestartStrategy.h
│   │   ├── RestartStrategy.cpp
│   │   ├── ProcessEvents.h
│   │   └── ProcessEvents.cpp
│   ├── platform/                          # Platform-specific code
│   │   ├── ProcessManager.h               # Abstract interface
│   │   ├── windows/
│   │   │   ├── WindowsProcessManager.h
│   │   │   ├── WindowsProcessManager.cpp
│   │   │   ├── WindowsService.h
│   │   │   └── WindowsService.cpp
│   │   └── unix/
│   │       ├── UnixProcessManager.h
│   │       ├── UnixProcessManager.cpp
│   │       ├── LinuxDaemon.h
│   │       └── LinuxDaemon.cpp
│   ├── utils/                             # Utility classes
│   │   ├── JsonUtils.h
│   │   ├── JsonUtils.cpp
│   │   ├── FileUtils.h
│   │   ├── FileUtils.cpp
│   │   ├── StringUtils.h
│   │   ├── StringUtils.cpp
│   │   ├── SystemUtils.h
│   │   ├── SystemUtils.cpp
│   │   ├── TimeUtils.h
│   │   └── TimeUtils.cpp
│   ├── middleware/                        # Drogon Middleware
│   │   ├── AuthMiddleware.h
│   │   ├── AuthMiddleware.cpp
│   │   ├── CorsMiddleware.h
│   │   ├── CorsMiddleware.cpp
│   │   ├── LoggingMiddleware.h
│   │   ├── LoggingMiddleware.cpp
│   │   ├── RateLimitMiddleware.h
│   │   └── RateLimitMiddleware.cpp
│   ├── filters/                           # Drogon Filters
│   │   ├── AuthFilter.h
│   │   ├── AuthFilter.cpp
│   │   ├── ValidationFilter.h
│   │   └── ValidationFilter.cpp
│   ├── plugins/                           # Drogon Plugins
│   │   ├── ProcessMonitorPlugin.h
│   │   ├── ProcessMonitorPlugin.cpp
│   │   ├── ConfigPlugin.h
│   │   └── ConfigPlugin.cpp
│   ├── websocket/                         # WebSocket handlers
│   │   ├── ProcessWebSocket.h
│   │   ├── ProcessWebSocket.cpp
│   │   ├── SystemWebSocket.h
│   │   ├── SystemWebSocket.cpp
│   │   ├── WebSocketManager.h
│   │   └── WebSocketManager.cpp
│   ├── tests/                             # Unit tests
│   │   ├── unit/
│   │   │   ├── TestProcessMonitor.cpp
│   │   │   ├── TestProcessManager.cpp
│   │   │   ├── TestHealthChecker.cpp
│   │   │   ├── TestRestartStrategy.cpp
│   │   │   ├── TestControllers.cpp
│   │   │   └── TestServices.cpp
│   │   ├── integration/
│   │   │   ├── TestApiEndpoints.cpp
│   │   │   ├── TestWebSocket.cpp
│   │   │   ├── TestProcessLifecycle.cpp
│   │   │   └── TestRestartScenarios.cpp
│   │   ├── mocks/
│   │   │   ├── MockProcessManager.h
│   │   │   ├── MockHealthChecker.h
│   │   │   └── MockNotificationService.h
│   │   └── data/
│   │       ├── test_processes.json
│   │       ├── test_config.json
│   │       └── mock_executables/
│   ├── scripts/                           # Build and utility scripts
│   │   ├── build_debug.sh
│   │   ├── build_release.sh
│   │   ├── run_tests.sh
│   │   ├── generate_docs.sh
│   │   └── install_deps.sh
│   ├── docs/                              # Backend documentation
│   │   ├── api_reference.md
│   │   ├── architecture.md
│   │   ├── configuration.md
│   │   ├── deployment.md
│   │   └── troubleshooting.md
│   ├── logs/                              # Log files
│   │   ├── .gitkeep
│   │   └── README.md
│   ├── data/                              # Data storage
│   │   ├── processes.json
│   │   ├── config.json
│   │   └── .gitkeep
│   └── build/                             # Build output
│       └── .gitkeep
├── frontend/                              # React Frontend
│   ├── package.json
│   ├── package-lock.json
│   ├── .env
│   ├── .env.development
│   ├── .env.production
│   ├── .gitignore
│   ├── public/
│   │   ├── index.html
│   │   ├── favicon.ico
│   │   ├── manifest.json
│   │   ├── logo192.png
│   │   ├── logo512.png
│   │   └── robots.txt
│   ├── src/
│   │   ├── index.js                       # Entry point
│   │   ├── App.js                         # Main App component
│   │   ├── App.css
│   │   ├── index.css
│   │   ├── components/                    # Reusable components
│   │   │   ├── common/
│   │   │   │   ├── Header.jsx
│   │   │   │   ├── Sidebar.jsx
│   │   │   │   ├── Footer.jsx
│   │   │   │   ├── Loading.jsx
│   │   │   │   ├── ErrorBoundary.jsx
│   │   │   │   ├── Modal.jsx
│   │   │   │   ├── Toast.jsx
│   │   │   │   └── Breadcrumb.jsx
│   │   │   ├── process/
│   │   │   │   ├── ProcessCard.jsx
│   │   │   │   ├── ProcessList.jsx
│   │   │   │   ├── ProcessDetails.jsx
│   │   │   │   ├── ProcessActions.jsx
│   │   │   │   ├── ProcessStats.jsx
│   │   │   │   ├── ProcessForm.jsx
│   │   │   │   └── ProcessFilter.jsx
│   │   │   ├── charts/
│   │   │   │   ├── LineChart.jsx
│   │   │   │   ├── BarChart.jsx
│   │   │   │   ├── PieChart.jsx
│   │   │   │   ├── RealTimeChart.jsx
│   │   │   │   └── ChartContainer.jsx
│   │   │   ├── forms/
│   │   │   │   ├── ConfigForm.jsx
│   │   │   │   ├── SettingsForm.jsx
│   │   │   │   ├── FormField.jsx
│   │   │   │   └── FormValidation.jsx
│   │   │   ├── tables/
│   │   │   │   ├── DataTable.jsx
│   │   │   │   ├── SortableTable.jsx
│   │   │   │   └── FilterableTable.jsx
│   │   │   └── navigation/
│   │   │       ├── MainNavigation.jsx
│   │   │       ├── TabNavigation.jsx
│   │   │       └── PageNavigation.jsx
│   │   ├── pages/                         # Page components
│   │   │   ├── Dashboard.jsx
│   │   │   ├── ProcessManager.jsx
│   │   │   ├── Configuration.jsx
│   │   │   ├── Logs.jsx
│   │   │   ├── Analytics.jsx
│   │   │   ├── Settings.jsx
│   │   │   ├── Login.jsx
│   │   │   └── NotFound.jsx
│   │   ├── services/                      # API services
│   │   │   ├── api.js                     # Base API configuration
│   │   │   ├── websocket.js               # WebSocket service
│   │   │   ├── processService.js          # Process API calls
│   │   │   ├── systemService.js           # System API calls
│   │   │   ├── configService.js           # Configuration API calls
│   │   │   ├── logService.js              # Log API calls
│   │   │   └── authService.js             # Authentication API calls
│   │   ├── hooks/                         # Custom React hooks
│   │   │   ├── useWebSocket.js
│   │   │   ├── useProcessMonitor.js
│   │   │   ├── useRealTimeData.js
│   │   │   ├── useLocalStorage.js
│   │   │   ├── useApi.js
│   │   │   ├── useAuth.js
│   │   │   └── useNotification.js
│   │   ├── context/                       # React Context
│   │   │   ├── AuthContext.js
│   │   │   ├── ProcessContext.js
│   │   │   ├── NotificationContext.js
│   │   │   ├── ThemeContext.js
│   │   │   └── WebSocketContext.js
│   │   ├── utils/                         # Utility functions
│   │   │   ├── dateUtils.js
│   │   │   ├── formatUtils.js
│   │   │   ├── validationUtils.js
│   │   │   ├── storageUtils.js
│   │   │   ├── constants.js
│   │   │   └── helpers.js
│   │   ├── styles/                        # Styling
│   │   │   ├── globals.css
│   │   │   ├── variables.css
│   │   │   ├── components.css
│   │   │   └── themes/
│   │   │       ├── lightTheme.js
│   │   │       └── darkTheme.js
│   │   └── tests/                         # Frontend tests
│   │       ├── components/
│   │       ├── pages/
│   │       ├── services/
│   │       ├── hooks/
│   │       ├── utils/
│   │       └── __mocks__/
│   ├── build/                             # Production build
│   └── node_modules/
├── docs/                                  # Project documentation
│   ├── README.md
│   ├── INSTALLATION.md
│   ├── CONFIGURATION.md
│   ├── API_REFERENCE.md
│   ├── DEVELOPMENT.md
│   ├── DEPLOYMENT.md
│   ├── TROUBLESHOOTING.md
│   ├── CHANGELOG.md
│   ├── architecture/
│   │   ├── system_overview.md
│   │   ├── backend_architecture.md
│   │   ├── frontend_architecture.md
│   │   ├── database_design.md
│   │   └── security_design.md
│   ├── api/
│   │   ├── rest_api.md
│   │   ├── websocket_api.md
│   │   ├── authentication.md
│   │   └── error_codes.md
│   ├── frontend/
│   │   ├── component_guide.md
│   │   ├── state_management.md
│   │   ├── styling_guide.md
│   │   └── testing_guide.md
│   ├── backend/
│   │   ├── drogon_integration.md
│   │   ├── process_monitoring.md
│   │   ├── platform_support.md
│   │   └── configuration_guide.md
│   ├── deployment/
│   │   ├── docker_deployment.md
│   │   ├── production_deployment.md
│   │   ├── monitoring_setup.md
│   │   └── backup_recovery.md
│   └── examples/
│       ├── configuration_examples.json
│       ├── api_usage_examples.md
│       └── integration_examples.md
├── scripts/                               # Build and deployment scripts
│   ├── build_all.sh
│   ├── build_backend.sh
│   ├── build_frontend.sh
│   ├── run_development.sh
│   ├── run_production.sh
│   ├── test_all.sh
│   ├── deploy.sh
│   ├── setup_dev_env.sh
│   ├── clean_build.sh
│   └── generate_docs.sh
├── docker/                                # Docker configuration
│   ├── docker-compose.yml
│   ├── docker-compose.dev.yml
│   ├── docker-compose.prod.yml
│   ├── backend/
│   │   ├── Dockerfile
│   │   ├── Dockerfile.dev
│   │   └── entrypoint.sh
│   ├── frontend/
│   │   ├── Dockerfile
│   │   ├── Dockerfile.dev
│   │   └── nginx.conf
│   └── nginx/
│       ├── Dockerfile
│       ├── nginx.conf
│       └── ssl/
├── tools/                                 # Development tools
│   ├── code_generators/
│   │   ├── generate_controller.py
│   │   ├── generate_service.py
│   │   └── generate_model.py
│   ├── testing/
│   │   ├── load_test.py
│   │   ├── api_test.py
│   │   └── mock_processes.py
│   └── deployment/
│       ├── health_check.py
│       ├── config_validator.py
│       └── backup_script.py
├── config/                                # Configuration files
│   ├── development/
│   │   ├── config.json
│   │   ├── processes.json
│   │   └── logging.json
│   ├── production/
│   │   ├── config.json
│   │   ├── processes.json
│   │   └── logging.json
│   └── testing/
│       ├── config.json
│       └── test_processes.json
├── logs/                                  # Log files
│   ├── .gitkeep
│   └── README.md
├── packaging/                             # Package creation files
│   ├── debian/
│   │   ├── control
│   │   ├── rules
│   │   ├── install
│   │   └── postinst
│   ├── rpm/
│   │   ├── processmonitor.spec
│   │   └── scripts/
│   ├── windows/
│   │   ├── installer.nsi
│   │   ├── setup.iss
│   │   └── assets/
│   └── docker/
│       ├── build_images.sh
│       └── push_images.sh
└── .github/                               # GitHub Actions
    ├── workflows/
    │   ├── ci.yml
    │   ├── cd.yml
    │   ├── tests.yml
    │   └── docker.yml
    ├── ISSUE_TEMPLATE/
    │   ├── bug_report.md
    │   ├── feature_request.md
    │   └── question.md
    └── PULL_REQUEST_TEMPLATE.md