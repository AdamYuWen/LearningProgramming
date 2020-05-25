library(shiny)

shinyServer(function(input, output) {
  # Select input file ----------
  output$select_file <- renderUI({
    if (is.null(input$file)) {
      return()
    } else {
      list(hr(),
           selectInput("select", "Select a file",
                       choices = input$file$name))
    }
  })

  # Generate outputs ----------
  df <- reactive({
    if (is.null(input$file)) {
      return()
    } else {
      read.table(file = input$file$datapath[input$file$name == input$select],
                 sep = input$separator,
                 header = input$header,
                 stringsAsFactors = input$stringAsFactors)
    }
  })

  output$file_df <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
       input$file
    }
  })

  output$data <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
      df()
    }
  })

  output$summary <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
      summary(df())
    }
  })

  output$datamerge <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
      num_file <- nrow(input$file)

      csv <- list()
      for (i in 1:num_file) {
        csv[[i]] <- read.csv(input$file$datapath[i])
      }
      do.call(rbind, csv)
    }
  })

  # Use a Rdata file to store the number of hits.
  output$counter <- renderText({
    if (!file.exists("counter.Rdata")) {
      counter <- 0
    } else {
      load(file = "counter.Rdata")
    }
    counter <- counter + 1
    save(counter, file = "counter.Rdata")
    paste0("Hits: ", counter)
  })

  # Show outputs ---------
  output$tab <- renderUI({
    if (is.null(input$file)) {
      return()
    } else {
    tabsetPanel(type = "tab",
                tabPanel(title = "About file", tableOutput("file_df")),
                tabPanel(title = "Data", tableOutput("data")),
                tabPanel(title = "Summary", tableOutput("summary")),
                tabPanel(title = "Merge", tableOutput("datamerge")))
    }
  })
})
